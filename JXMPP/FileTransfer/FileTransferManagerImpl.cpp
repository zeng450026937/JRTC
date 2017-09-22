/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/FileTransfer/FileTransferManagerImpl.h>

#include <boost/bind.hpp>
#include <boost/cstdint.hpp>
#include <boost/filesystem.hpp>

#include <JXMPP/Base/BoostFilesystemVersion.h>
#include <JXMPP/Base/Log.h>
#include <JXMPP/Base/Path.h>
#include <JXMPP/Disco/EntityCapsProvider.h>
#include <JXMPP/Disco/FeatureOracle.h>
#include <JXMPP/Elements/JingleFileTransferFileInfo.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/FileTransfer/DefaultFileTransferTransporterFactory.h>
#include <JXMPP/FileTransfer/IncomingFileTransferManager.h>
#include <JXMPP/FileTransfer/OutgoingFileTransferManager.h>
#include <JXMPP/FileTransfer/SOCKS5BytestreamProxiesManager.h>
#include <JXMPP/FileTransfer/SOCKS5BytestreamRegistry.h>
#include <JXMPP/FileTransfer/SOCKS5BytestreamServerManager.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Network/ConnectionFactory.h>
#include <JXMPP/Network/ConnectionServerFactory.h>
#include <JXMPP/Network/HostAddress.h>
#include <JXMPP/Network/NATTraverser.h>
#include <JXMPP/Presence/PresenceOracle.h>
#include <JXMPP/Queries/IQRouter.h>

namespace JXMPP {

FileTransferManagerImpl::FileTransferManagerImpl(
        const JID& ownJID,
        JingleSessionManager* jingleSessionManager,
        IQRouter* router,
        EntityCapsProvider* capsProvider,
        PresenceOracle* presOracle,
        ConnectionFactory* connectionFactory,
        ConnectionServerFactory* connectionServerFactory,
        TimerFactory* timerFactory,
        DomainNameResolver* domainNameResolver,
        NetworkEnvironment* networkEnvironment,
        NATTraverser* natTraverser,
        CryptoProvider* crypto) :
            iqRouter(router),
            capsProvider(capsProvider),
            presenceOracle(presOracle) {
    bytestreamRegistry = new SOCKS5BytestreamRegistry();
    s5bServerManager = new SOCKS5BytestreamServerManager(
            bytestreamRegistry, connectionServerFactory, networkEnvironment, natTraverser);
    bytestreamProxy = new SOCKS5BytestreamProxiesManager(connectionFactory, timerFactory, domainNameResolver, iqRouter, JID(ownJID.getDomain()));

    transporterFactory = new DefaultFileTransferTransporterFactory(
            bytestreamRegistry,
            s5bServerManager,
            bytestreamProxy,
            &idGenerator,
            connectionFactory,
            timerFactory,
            crypto,
            iqRouter);
    outgoingFTManager = new OutgoingFileTransferManager(
            jingleSessionManager,
            iqRouter,
            transporterFactory,
            timerFactory,
            crypto);
    incomingFTManager = new IncomingFileTransferManager(
            jingleSessionManager,
            transporterFactory,
            timerFactory,
            crypto);
    incomingFTManager->onIncomingFileTransfer.connect(onIncomingFileTransfer);
}

FileTransferManagerImpl::~FileTransferManagerImpl() {
    delete incomingFTManager;
    delete outgoingFTManager;
    delete transporterFactory;
    delete bytestreamProxy;
    delete s5bServerManager;
    delete bytestreamRegistry;
}

void FileTransferManagerImpl::start() {
}

void FileTransferManagerImpl::stop() {
    s5bServerManager->stop();
}

OutgoingFileTransfer::ref FileTransferManagerImpl::createOutgoingFileTransfer(
        const JID& to,
        const boost::filesystem::path& filepath,
        const std::string& description,
        std::shared_ptr<ReadBytestream> bytestream,
        const FileTransferOptions& config) {
#if BOOST_FILESYSTEM_VERSION == 2 // TODO: Delete this when boost 1.44 becomes a minimum requirement, and we no longer need v2
    std::string filename = filepath.filename();
#else
    std::string filename = pathToString(filepath.filename());
#endif

    boost::uintmax_t sizeInBytes = boost::filesystem::file_size(filepath);
    boost::posix_time::ptime lastModified = boost::posix_time::from_time_t(boost::filesystem::last_write_time(filepath));
    return createOutgoingFileTransfer(to, filename, description, sizeInBytes, lastModified, bytestream, config);
}

OutgoingFileTransfer::ref FileTransferManagerImpl::createOutgoingFileTransfer(
        const JID& to,
        const std::string& filename,
        const std::string& description,
        const boost::uintmax_t sizeInBytes,
        const boost::posix_time::ptime& lastModified,
        std::shared_ptr<ReadBytestream> bytestream,
        const FileTransferOptions& config) {
    JingleFileTransferFileInfo fileInfo;
    fileInfo.setDate(lastModified);
    fileInfo.setSize(sizeInBytes);
    fileInfo.setName(filename);
    fileInfo.setDescription(description);

    JID receipient = to;

    if(receipient.isBare()) {
        auto featureOracle = FeatureOracle(capsProvider, presenceOracle);
        JID fullJID = featureOracle.getMostAvailableClientForFileTrasfer(receipient);
        if (!fullJID.toString().empty()) {
            receipient = fullJID;
        } else {
            return OutgoingFileTransfer::ref();
        }
    }

    assert(!iqRouter->getJID().isBare());

    DiscoInfo::ref capabilities = capsProvider->getCaps(receipient);

    FileTransferOptions options = config;
    if (capabilities) {
        if (!capabilities->hasFeature(DiscoInfo::JingleTransportsS5BFeature)) {
            options = options.withAssistedAllowed(false).withDirectAllowed(false).withProxiedAllowed(false);
        }
        if (!capabilities->hasFeature(DiscoInfo::JingleTransportsIBBFeature)) {
            options = options.withInBandAllowed(false);
        }
    }
    else {
        JXMPP_LOG(warning) << "No entity capabilities information for " << receipient.toString() << std::endl;
    }

    return outgoingFTManager->createOutgoingFileTransfer(iqRouter->getJID(), receipient, bytestream, fileInfo, options);
}

}
