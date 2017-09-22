#ifndef JXMPP_PUBSUBPUBLISH_H
#define JXMPP_PUBSUBPUBLISH_H

#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubItem.h>
#include <JXMPP/Elements/PubSubPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubPublish : public PubSubPayload {
        public:

            PubSubPublish();

            virtual ~PubSubPublish();

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


        private:
            std::string node;
            std::vector< std::shared_ptr<PubSubItem> > items;
    };
}

#endif // JXMPP_PUBSUBPUBLISH_H
