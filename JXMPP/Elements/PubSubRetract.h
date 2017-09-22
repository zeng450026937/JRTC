#ifndef JXMPP_PUBSUBRETRACT_H
#define JXMPP_PUBSUBRETRACT_H

#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubItem.h>
#include <JXMPP/Elements/PubSubPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubRetract : public PubSubPayload {
        public:

            PubSubRetract();

            virtual ~PubSubRetract();

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

            boost::optional<bool> isNotify() const {
                return notify;
            }

            void setNotify(const boost::optional<bool>& value) {
                this->notify = value ;
            }


        private:
            std::string node;
            std::vector< std::shared_ptr<PubSubItem> > items;
            boost::optional<bool> notify;
    };
}

#endif // JXMPP_PUBSUBRETRACT_H
