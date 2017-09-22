#include <JXMPP/FileTransfer/IncomingFileTransferManager.h>

#include <memory>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Elements/JingleDescription.h>
#include <JXMPP/Elements/JingleFileTransferDescription.h>
#include <JXMPP/Elements/JingleIBBTransportPayload.h>
#include <JXMPP/Elements/JingleS5BTransportPayload.h>
#include <JXMPP/FileTransfer/IncomingJingleFileTransfer.h>
#include <JXMPP/Jingle/Jingle.h>
#include <JXMPP/Jingle/JingleSessionManager.h>

namespace JXMPP {

IncomingFileTransferManager::IncomingFileTransferManager(
        JingleSessionManager* jingleSessionManager,
        FileTransferTransporterFactory* transporterFactory,
        TimerFactory* timerFactory,
        CryptoProvider* crypto) :
            jingleSessionManager(jingleSessionManager),
            transporterFactory(transporterFactory),
            timerFactory(timerFactory),
            crypto(crypto) {
    jingleSessionManager->addIncomingSessionHandler(this);
}

IncomingFileTransferManager::~IncomingFileTransferManager() {
    jingleSessionManager->removeIncomingSessionHandler(this);
}

bool IncomingFileTransferManager::handleIncomingJingleSession(
        JingleSession::ref session,
        const std::vector<JingleContentPayload::ref>& contents,
        const JID& recipient) {
    if (JingleContentPayload::ref content = Jingle::getContentWithDescription<JingleFileTransferDescription>(contents)) {
        if (content->getTransport<JingleS5BTransportPayload>() || content->getTransport<JingleIBBTransportPayload>()) {
            JingleFileTransferDescription::ref description = content->getDescription<JingleFileTransferDescription>();
            if (description) {
                IncomingJingleFileTransfer::ref transfer = std::make_shared<IncomingJingleFileTransfer>(
                        recipient, session, content, transporterFactory, timerFactory, crypto);
                onIncomingFileTransfer(transfer);
            }
            else {
                JXMPP_LOG(warning) << "Received a file-transfer request with no file description.";
                session->sendTerminate(JinglePayload::Reason::FailedApplication);
            }
        }
        else {
            session->sendTerminate(JinglePayload::Reason::UnsupportedTransports);
        }
        return true;
    }
    else {
        return false;
    }
}


}
