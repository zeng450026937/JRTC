#ifndef JXMPP_PUBSUBOWNERSUBSCRIPTION_H
#define JXMPP_PUBSUBOWNERSUBSCRIPTION_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerSubscription : public Payload {
        public:
            enum SubscriptionType {
                None,
                Pending,
                Subscribed,
                Unconfigured
            };

            PubSubOwnerSubscription();

            virtual ~PubSubOwnerSubscription();

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


        private:
            JID jid;
            SubscriptionType subscription;
    };
}

#endif // JXMPP_PUBSUBOWNERSUBSCRIPTION_H
