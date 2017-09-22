#ifndef JXMPP_PUBSUBUNSUBSCRIBE_H
#define JXMPP_PUBSUBUNSUBSCRIBE_H

#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubPayload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API PubSubUnsubscribe : public PubSubPayload {
        public:

            PubSubUnsubscribe();

            virtual ~PubSubUnsubscribe();

            const boost::optional< std::string >& getNode() const {
                return node;
            }

            void setNode(const boost::optional< std::string >& value) {
                this->node = value ;
            }

            const JID& getJID() const {
                return jid;
            }

            void setJID(const JID& value) {
                this->jid = value ;
            }

            const boost::optional< std::string >& getSubscriptionID() const {
                return subscriptionID;
            }

            void setSubscriptionID(const boost::optional< std::string >& value) {
                this->subscriptionID = value ;
            }


        private:
            boost::optional< std::string > node;
            JID jid;
            boost::optional< std::string > subscriptionID;
    };
}

#endif // JXMPP_PUBSUBUNSUBSCRIBE_H
