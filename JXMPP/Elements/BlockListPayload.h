#ifndef JXMPP_BLOCKLISTPAYLOAD_H
#define JXMPP_BLOCKLISTPAYLOAD_H

#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API BlockListPayload : public Payload {
        public:
            BlockListPayload(const std::vector<JID>& items = std::vector<JID>()) : items(items) {
            }

            void addItem(const JID& item) {
                items.push_back(item);
            }

            const std::vector<JID>& getItems() const {
                return items;
            }

        private:
            std::vector<JID> items;
    };
}

#endif // JXMPP_BLOCKLISTPAYLOAD_H
