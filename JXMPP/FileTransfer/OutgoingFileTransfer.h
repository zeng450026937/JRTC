#ifndef JXMPP_OUTGOINGFILETRANSFER_H
#define JXMPP_OUTGOINGFILETRANSFER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/FileTransfer.h>

namespace JXMPP {
    class JXMPP_API OutgoingFileTransfer : public FileTransfer {
        public:
            typedef std::shared_ptr<OutgoingFileTransfer> ref;
        public:
            virtual ~OutgoingFileTransfer();

            virtual void start() = 0;
    };
}

#endif // JXMPP_OUTGOINGFILETRANSFER_H
