#ifndef JXMPP_OUTGOINGFILETRANSFERMANAGER_H
#define JXMPP_OUTGOINGFILETRANSFERMANAGER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JingleSessionManager;
    class IQRouter;
    class FileTransferTransporterFactory;
    class OutgoingFileTransfer;
    class JID;
    class IDGenerator;
    class ReadBytestream;
    class JingleFileTransferFileInfo;
    class CryptoProvider;
    class FileTransferOptions;
    class TimerFactory;

    class JXMPP_API OutgoingFileTransferManager {
        public:
            OutgoingFileTransferManager(
                    JingleSessionManager* jingleSessionManager,
                    IQRouter* router,
                    FileTransferTransporterFactory* transporterFactory,
                    TimerFactory* timerFactory,
                    CryptoProvider* crypto);
            ~OutgoingFileTransferManager();

            std::shared_ptr<OutgoingFileTransfer> createOutgoingFileTransfer(
                    const JID& from,
                    const JID& to,
                    std::shared_ptr<ReadBytestream>,
                    const JingleFileTransferFileInfo&,
                    const FileTransferOptions&);

        private:
            JingleSessionManager* jingleSessionManager;
            IQRouter* iqRouter;
            FileTransferTransporterFactory* transporterFactory;
            TimerFactory* timerFactory;
            IDGenerator* idGenerator;
            CryptoProvider* crypto;
    };
}

#endif // JXMPP_OUTGOINGFILETRANSFERMANAGER_H
