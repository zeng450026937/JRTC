#ifndef JXMPP_REQUEST_H
#define JXMPP_REQUEST_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Queries/IQHandler.h>

namespace JXMPP {
    class IQRouter;

    /**
     * An IQ get/set request query.
     */
    class JXMPP_API Request : public IQHandler, public std::enable_shared_from_this<Request> {
        public:
            std::string send();

            const JID& getReceiver() const {
                return receiver_;
            }

            /**
             * Returns the ID of this request.
             * This will only be set after send() is called.
             */
            const std::string& getID() const {
                return id_;
            }


        protected:
            /**
             * Constructs a request of a certain type to a specific receiver, and attaches the given
             * payload.
             */
            Request(
                    IQ::Type type,
                    const JID& receiver,
                    std::shared_ptr<Payload> payload,
                    IQRouter* router);

            /**
             * Constructs a request of a certain type to a specific receiver from a specific sender, and attaches the given
             * payload.
             */
            Request(
                    IQ::Type type,
                    const JID& sender,
                    const JID& receiver,
                    std::shared_ptr<Payload> payload,
                    IQRouter* router);


            /**
             * Constructs a request of a certain type to a specific receiver.
             */
            Request(
                    IQ::Type type,
                    const JID& receiver,
                    IQRouter* router);

            /**
             * Constructs a request of a certain type to a specific receiver from a specific sender.
             */
            Request(
                    IQ::Type type,
                    const JID& sender,
                    const JID& receiver,
                    IQRouter* router);


            virtual void setPayload(std::shared_ptr<Payload> payload) {
                payload_ = payload;
            }

            std::shared_ptr<Payload> getPayload() const {
                return payload_;
            }

            virtual void handleResponse(std::shared_ptr<Payload>, std::shared_ptr<ErrorPayload>) = 0;

        private:
            bool handleIQ(std::shared_ptr<IQ>);
            bool isCorrectSender(const JID& jid);

        private:
            IQRouter* router_;
            IQ::Type type_;
            JID sender_;
            JID receiver_;
            std::shared_ptr<Payload> payload_;
            std::string id_;
            bool sent_;
    };
}

#endif // JXMPP_REQUEST_H
