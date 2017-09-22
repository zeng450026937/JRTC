#ifndef JXMPP_IBBRECEIVESESSION_H
#define JXMPP_IBBRECEIVESESSION_H

#include <memory>

#include <boost/optional/optional.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IBB.h>
#include <JXMPP/FileTransfer/FileTransferError.h>
#include <JXMPP/FileTransfer/WriteBytestream.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class IQRouter;

    class JXMPP_API IBBReceiveSession {
        public:
            IBBReceiveSession(
                    const std::string& id,
                    const JID& from,
                    const JID& to,
                    unsigned long long size,
                    std::shared_ptr<WriteBytestream> bytestream,
                    IQRouter* router);
            ~IBBReceiveSession();

            void start();
            void stop();

            const JID& getSender() const {
                return from;
            }

            const JID& getReceiver() const {
                return to;
            }

            boost::signals2::signal<void (boost::optional<FileTransferError>)> onFinished;

        private:
            bool handleSetRequest(const JID& from, const JID& to, const std::string& id, IBB::ref payload);
            void finish(boost::optional<FileTransferError>);

        private:
            class IBBResponder;
            friend class IBBResponder;

            std::string id;
            JID from;
            JID to;
            unsigned long long size;
            std::shared_ptr<WriteBytestream> bytestream;
            IQRouter* router;
            IBBResponder* responder;
            bool active;
    };
}

#endif // JXMPP_IBBRECEIVESESSION_H
