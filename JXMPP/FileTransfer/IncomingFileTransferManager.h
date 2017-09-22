#ifndef JXMPP_INCOMINGFILETRANSFERMANAGER_H
#define JXMPP_INCOMINGFILETRANSFERMANAGER_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/IncomingFileTransfer.h>
#include <JXMPP/Jingle/IncomingJingleSessionHandler.h>

namespace JXMPP {
    class JingleSessionManager;
    class FileTransferTransporterFactory;
    class TimerFactory;
    class CryptoProvider;

    class JXMPP_API IncomingFileTransferManager : public IncomingJingleSessionHandler {
        public:
            IncomingFileTransferManager(
                    JingleSessionManager* jingleSessionManager,
                    FileTransferTransporterFactory* transporterFactory,
                    TimerFactory* timerFactory,
                    CryptoProvider* crypto);
            virtual ~IncomingFileTransferManager();

            boost::signals2::signal<void (IncomingFileTransfer::ref)> onIncomingFileTransfer;

        private:
            bool handleIncomingJingleSession(
                    JingleSession::ref session,
                    const std::vector<JingleContentPayload::ref>& contents,
                    const JID& recipient);

        private:
            JingleSessionManager* jingleSessionManager;
            FileTransferTransporterFactory* transporterFactory;
            TimerFactory* timerFactory;
            CryptoProvider* crypto;
    };
}

#endif // JXMPP_INCOMINGFILETRANSFERMANAGER_H
