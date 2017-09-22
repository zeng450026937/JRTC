#include <JXMPP/Elements/RosterPayload.h>

namespace JXMPP {

boost::optional<RosterItemPayload> RosterPayload::getItem(const JID& jid) const {
    for (const auto& item : items_) {
        // FIXME: MSVC rejects this. Find out why.
        //if (item.getJID() == jid) {
        if (item.getJID().equals(jid, JID::WithResource)) {
            return boost::optional<RosterItemPayload>(item);
        }
    }
    return boost::optional<RosterItemPayload>();
}

}
