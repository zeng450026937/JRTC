#ifndef JXMPP_FILETRANSFERMANAGERIMPL_H
#define JXMPP_FILETRANSFERMANAGERIMPL_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <string>
#include <vector>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/IDGenerator.h>
#include <JXMPP/Elements/S5BProxyRequest.h>
#include <JXMPP/FileTransfer/FileTransferManager.h>
#include <JXMPP/FileTransfer/FileTransferOptions.h>
#include <JXMPP/FileTransfer/IncomingFileTransfer.h>
#include <JXMPP/FileTransfer/OutgoingFileTransfer.h>

namespace JXMPP {
    class ConnectionFactory;
    class ConnectionServerFactory;
    class CryptoProvider;
    class DomainNameResolver;
    class EntityCapsProvider;
    class FileTransferTransporterFactory;
    class IQRouter;
    class IncomingFileTransferManager;
    class JID;
    class JingleSessionManager;
    class NATTraverser;
    class NetworkEnvironment;
    class OutgoingFileTransferManager;
    class PresenceOracle;
    class ReadBytestream;
    class SOCKS5BytestreamProxiesManager;
    class SOCKS5BytestreamRegistry;
    class SOCKS5BytestreamServerManager;
    class TimerFactory;

    class JXMPP_API FileTransferManagerImpl : public FileTransferManager {
        public:
            FileTransferManagerImpl(
                    const JID& ownFullJID,
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
                    CryptoProvider* crypto);
            virtual ~FileTransferManagerImpl() override;

            OutgoingFileTransfer::ref createOutgoingFileTransfer(
                    const JID& to,
                    const boost::filesystem::path& filepath,
                    const std::string& description,
                    std::shared_ptr<ReadBytestream> bytestream,
                    const FileTransferOptions&) override;
            OutgoingFileTransfer::ref createOutgoingFileTransfer(
                    const JID& to,
                    const std::string& filename,
                    const std::string& description,
                    const boost::uintmax_t sizeInBytes,
                    const boost::posix_time::ptime& lastModified,
                    std::shared_ptr<ReadBytestream> bytestream,
                    const FileTransferOptions&) override;

            void start();
            void stop();

        private:
            boost::optional<JID> highestPriorityJIDSupportingFileTransfer(const JID& bareJID);

        private:
            OutgoingFileTransferManager* outgoingFTManager;
            IncomingFileTransferManager* incomingFTManager;
            FileTransferTransporterFactory* transporterFactory;
            IQRouter* iqRouter;
            EntityCapsProvider* capsProvider;
            PresenceOracle* presenceOracle;
            IDGenerator idGenerator;
            SOCKS5BytestreamRegistry* bytestreamRegistry;
            SOCKS5BytestreamProxiesManager* bytestreamProxy;
            SOCKS5BytestreamServerManager* s5bServerManager;
    };
}

#endif // JXMPP_FILETRANSFERMANAGERIMPL_H
