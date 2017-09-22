#ifndef JXMPP_INCOMINGFILETRANSFER_H
#define JXMPP_INCOMINGFILETRANSFER_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/FileTransfer/FileTransfer.h>
#include <JXMPP/FileTransfer/FileTransferOptions.h>

namespace JXMPP {
    class WriteBytestream;
    class JID;

    /**
     * @brief The IncomingFileTransfer abstract class is the general interface in Swiften
     * for incoming file transfers.
     */
    class JXMPP_API IncomingFileTransfer : public FileTransfer {
        public:
            typedef std::shared_ptr<IncomingFileTransfer> ref;

            virtual ~IncomingFileTransfer();

            virtual void accept(
                    std::shared_ptr<WriteBytestream>,
                    const FileTransferOptions& = FileTransferOptions()) = 0;

            virtual const JID& getSender() const = 0;
            virtual const JID& getRecipient() const = 0;
    };
}

#endif // JXMPP_INCOMINGFILETRANSFER_H
