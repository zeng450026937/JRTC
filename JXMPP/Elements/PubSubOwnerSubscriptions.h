#ifndef JXMPP_PUBSUBOWNERSUBSCRIPTIONS_H
#define JXMPP_PUBSUBOWNERSUBSCRIPTIONS_H

#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubOwnerPayload.h>
#include <JXMPP/Elements/PubSubOwnerSubscription.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerSubscriptions : public PubSubOwnerPayload {
        public:

            PubSubOwnerSubscriptions();

            virtual ~PubSubOwnerSubscriptions();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            const std::vector< std::shared_ptr<PubSubOwnerSubscription> >& getSubscriptions() const {
                return subscriptions;
            }

            void setSubscriptions(const std::vector< std::shared_ptr<PubSubOwnerSubscription> >& value) {
                this->subscriptions = value ;
            }

            void addSubscription(std::shared_ptr<PubSubOwnerSubscription> value) {
                this->subscriptions.push_back(value);
            }


        private:
            std::string node;
            std::vector< std::shared_ptr<PubSubOwnerSubscription> > subscriptions;
    };
}

#endif // JXMPP_PUBSUBOWNERSUBSCRIPTIONS_H
