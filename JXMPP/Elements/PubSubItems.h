#ifndef JXMPP_PUBSUBITEMS_H
#define JXMPP_PUBSUBITEMS_H

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubItem.h>
#include <JXMPP/Elements/PubSubPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubItems : public PubSubPayload {
        public:

            PubSubItems();
            PubSubItems(const std::string& node) : node(node) {}
            virtual ~PubSubItems();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            const std::vector< std::shared_ptr<PubSubItem> >& getItems() const {
                return items;
            }

            void setItems(const std::vector< std::shared_ptr<PubSubItem> >& value) {
                this->items = value ;
            }

            void addItem(std::shared_ptr<PubSubItem> value) {
                this->items.push_back(value);
            }

            const boost::optional< unsigned int >& getMaximumItems() const {
                return maximumItems;
            }

            void setMaximumItems(const boost::optional< unsigned int >& value) {
                this->maximumItems = value ;
            }

            const boost::optional< std::string >& getSubscriptionID() const {
                return subscriptionID;
            }

            void setSubscriptionID(const boost::optional< std::string >& value) {
                this->subscriptionID = value ;
            }


        private:
            std::string node;
            std::vector< std::shared_ptr<PubSubItem> > items;
            boost::optional< unsigned int > maximumItems;
            boost::optional< std::string > subscriptionID;
    };
}

#endif // JXMPP_PUBSUBITEMS_H
