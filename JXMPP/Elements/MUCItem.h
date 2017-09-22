#ifndef JXMPP_MUCITEM_H
#define JXMPP_MUCITEM_H

#include <JXMPP/Elements/MUCOccupant.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
struct MUCItem {
    MUCItem() {}
    MUCItem(MUCOccupant::Affiliation affiliation, const JID& jid, MUCOccupant::Role role) : realJID(jid), affiliation(affiliation), role(role) {}
    MUCItem(MUCOccupant::Affiliation affiliation, MUCOccupant::Role role) : affiliation(affiliation), role(role) {}
    boost::optional<JID> realJID;
    boost::optional<std::string> nick;
    boost::optional<MUCOccupant::Affiliation> affiliation;
    boost::optional<MUCOccupant::Role> role;
    boost::optional<JID> actor;
    boost::optional<std::string> reason;
};
}

#endif // JXMPP_MUCITEM_H
