/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/FileTransfer/OutgoingFileTransferManager.h>

#include <memory>

#include <JXMPP/Base/IDGenerator.h>
#include <JXMPP/FileTransfer/OutgoingJingleFileTransfer.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Jingle/JingleContentID.h>
#include <JXMPP/Jingle/JingleSessionImpl.h>
#include <JXMPP/Jingle/JingleSessionManager.h>

namespace JXMPP {

OutgoingFileTransferManager::OutgoingFileTransferManager(
        JingleSessionManager* jingleSessionManager,
        IQRouter* router,
        FileTransferTransporterFactory* transporterFactory,
        TimerFactory* timerFactory,
        CryptoProvider* crypto) :
            jingleSessionManager(jingleSessionManager),
            iqRouter(router),
            transporterFactory(transporterFactory),
            timerFactory(timerFactory),
            crypto(crypto) {
    idGenerator = new IDGenerator();
}

OutgoingFileTransferManager::~OutgoingFileTransferManager() {
    delete idGenerator;
}

std::shared_ptr<OutgoingFileTransfer> OutgoingFileTransferManager::createOutgoingFileTransfer(
        const JID& from,
        const JID& recipient,
        std::shared_ptr<ReadBytestream> readBytestream,
        const JingleFileTransferFileInfo& fileInfo,
        const FileTransferOptions& config) {
    JingleSessionImpl::ref jingleSession = std::make_shared<JingleSessionImpl>(
            from, recipient, idGenerator->generateID(), iqRouter);
    jingleSessionManager->registerOutgoingSession(from, jingleSession);
    return std::shared_ptr<OutgoingJingleFileTransfer>(new OutgoingJingleFileTransfer(
                recipient,
                jingleSession,
                readBytestream,
                transporterFactory,
                timerFactory,
                idGenerator,
                fileInfo,
                config,
                crypto));
}

}
