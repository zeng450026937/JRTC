#ifndef JXMPP_FILETRANSFERTRANSPORTERFACTORY_H
#define JXMPP_FILETRANSFERTRANSPORTERFACTORY_H

#include <string>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JID;
    class FileTransferTransporter;
    class FileTransferOptions;

    class JXMPP_API FileTransferTransporterFactory {
        public:
            virtual ~FileTransferTransporterFactory();

            virtual FileTransferTransporter* createInitiatorTransporter(
                    const JID& initiator,
                    const JID& responder,
                    const FileTransferOptions& options) = 0;
            virtual FileTransferTransporter* createResponderTransporter(
                    const JID& initiator,
                    const JID& responder,
                    const std::string& s5bSessionID,
                    const FileTransferOptions& options) = 0;
    };
}

#endif // JXMPP_FILETRANSFERTRANSPORTERFACTORY_H
