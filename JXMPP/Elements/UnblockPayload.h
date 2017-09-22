#ifndef JXMPP_UNBLOCKPAYLOAD_H
#define JXMPP_UNBLOCKPAYLOAD_H

#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API UnblockPayload : public Payload {
        public:
            UnblockPayload(const std::vector<JID>& jids = std::vector<JID>()) : items(jids) {
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

#endif // JXMPP_UNBLOCKPAYLOAD_H
