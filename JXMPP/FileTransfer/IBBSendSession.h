#ifndef JXMPP_IBBSENDSESSION_H
#define JXMPP_IBBSENDSESSION_H

#include <memory>

#include <boost/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/IBB.h>
#include <JXMPP/FileTransfer/FileTransferError.h>
#include <JXMPP/FileTransfer/ReadBytestream.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class IQRouter;
    class IBBRequest;

    class JXMPP_API IBBSendSession {
        public:
            IBBSendSession(
                    const std::string& id,
                    const JID& from,
                    const JID& to,
                    std::shared_ptr<ReadBytestream> bytestream,
                    IQRouter* router);
            ~IBBSendSession();

            void start();
            void stop();

            const JID& getSender() const {
                return from;
            }

            const JID& getReceiver() const {
                return to;
            }

            void setBlockSize(unsigned int blockSize) {
                this->blockSize = blockSize;
            }

            boost::signals2::signal<void (boost::optional<FileTransferError>)> onFinished;
            boost::signals2::signal<void (size_t)> onBytesSent;

        private:
            void handleIBBResponse(IBB::ref, ErrorPayload::ref);
            void finish(boost::optional<FileTransferError>);
            void sendMoreData();
            void handleDataAvailable();

        private:
            std::string id;
            JID from;
            JID to;
            std::shared_ptr<ReadBytestream> bytestream;
            IQRouter* router;
            unsigned int blockSize;
            int sequenceNumber;
            bool active;
            bool waitingForData;
            std::shared_ptr<IBBRequest> currentRequest;
    };
}

#endif // JXMPP_IBBSENDSESSION_H
