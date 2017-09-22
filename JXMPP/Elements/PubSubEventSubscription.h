#ifndef JXMPP_PUBSUBEVENTSUBSCRIPTION_H
#define JXMPP_PUBSUBEVENTSUBSCRIPTION_H

#include <string>

#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubEventPayload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API PubSubEventSubscription : public PubSubEventPayload {
        public:
            enum SubscriptionType {
                None,
                Pending,
                Subscribed,
                Unconfigured
            };

            PubSubEventSubscription();

            virtual ~PubSubEventSubscription();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            const JID& getJID() const {
                return jid;
            }

            void setJID(const JID& value) {
                this->jid = value ;
            }

            SubscriptionType getSubscription() const {
                return subscription;
            }

            void setSubscription(SubscriptionType value) {
                this->subscription = value ;
            }

            const boost::optional< std::string >& getSubscriptionID() const {
                return subscriptionID;
            }

            void setSubscriptionID(const boost::optional< std::string >& value) {
                this->subscriptionID = value ;
            }

            const boost::posix_time::ptime& getExpiry() const {
                return expiry;
            }

            void setExpiry(const boost::posix_time::ptime& value) {
                this->expiry = value ;
            }


        private:
            std::string node;
            JID jid;
            SubscriptionType subscription;
            boost::optional< std::string > subscriptionID;
            boost::posix_time::ptime expiry;
    };
}

#endif // JXMPP_PUBSUBEVENTSUBSCRIPTION_H
