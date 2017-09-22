#ifndef JXMPP_BLOCKPAYLOAD_H
#define JXMPP_BLOCKPAYLOAD_H

#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API BlockPayload : public Payload {
        public:
            BlockPayload(const std::vector<JID>& jids = std::vector<JID>()) : items(jids) {
            }

            void addItem(const JID& jid) {
                items.push_back(jid);
            }

            const std::vector<JID>& getItems() const {
                return items;
            }

        private:
            std::vector<JID> items;
    };
}

#endif // JXMPP_BLOCKPAYLOAD_H
