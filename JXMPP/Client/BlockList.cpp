#include <JXMPP/Client/BlockList.h>

#include <algorithm>

using namespace JXMPP;

BlockList::~BlockList() {

}

bool BlockList::isBlocked(const JID& jid) const {
    const std::vector<JID>& items = getItems();
    return (std::find(items.begin(), items.end(), jid.toBare()) != items.end()) ||
            (std::find(items.begin(), items.end(), JID(jid.getDomain())) != items.end()) ||
            (std::find(items.begin(), items.end(), jid) != items.end());
}
