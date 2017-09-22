#ifndef JXMPP_PUBSUBEVENTITEMS_H
#define JXMPP_PUBSUBEVENTITEMS_H

#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubEventItem.h>
#include <JXMPP/Elements/PubSubEventPayload.h>
#include <JXMPP/Elements/PubSubEventRetract.h>

namespace JXMPP {
    class JXMPP_API PubSubEventItems : public PubSubEventPayload {
        public:

            PubSubEventItems();

            virtual ~PubSubEventItems();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            const std::vector< std::shared_ptr<PubSubEventItem> >& getItems() const {
                return items;
            }

            void setItems(const std::vector< std::shared_ptr<PubSubEventItem> >& value) {
                this->items = value ;
            }

            void addItem(std::shared_ptr<PubSubEventItem> value) {
                this->items.push_back(value);
            }

            const std::vector< std::shared_ptr<PubSubEventRetract> >& getRetracts() const {
                return retracts;
            }

            void setRetracts(const std::vector< std::shared_ptr<PubSubEventRetract> >& value) {
                this->retracts = value ;
            }

            void addRetract(std::shared_ptr<PubSubEventRetract> value) {
                this->retracts.push_back(value);
            }


        private:
            std::string node;
            std::vector< std::shared_ptr<PubSubEventItem> > items;
            std::vector< std::shared_ptr<PubSubEventRetract> > retracts;
    };
}

#endif // JXMPP_PUBSUBEVENTITEMS_H
