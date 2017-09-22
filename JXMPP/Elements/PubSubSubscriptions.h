#ifndef JXMPP_PUBSUBSUBSCRIPTIONS_H
#define JXMPP_PUBSUBSUBSCRIPTIONS_H

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubPayload.h>
#include <JXMPP/Elements/PubSubSubscription.h>

namespace JXMPP {
    class JXMPP_API PubSubSubscriptions : public PubSubPayload {
        public:

            PubSubSubscriptions();
            PubSubSubscriptions(const std::string& node) : node(node) {}
            virtual ~PubSubSubscriptions();

            const boost::optional< std::string >& getNode() const {
                return node;
            }

            void setNode(const boost::optional< std::string >& value) {
                this->node = value ;
            }

            const std::vector< std::shared_ptr<PubSubSubscription> >& getSubscriptions() const {
                return subscriptions;
            }

            void setSubscriptions(const std::vector< std::shared_ptr<PubSubSubscription> >& value) {
                this->subscriptions = value ;
            }

            void addSubscription(std::shared_ptr<PubSubSubscription> value) {
                this->subscriptions.push_back(value);
            }


        private:
            boost::optional< std::string > node;
            std::vector< std::shared_ptr<PubSubSubscription> > subscriptions;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIPTIONS_H
