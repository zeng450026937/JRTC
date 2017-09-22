#include <JXMPP/Elements/MUCOccupant.h>

#include <utility>

namespace JXMPP {

MUCOccupant::MUCOccupant(const std::string &nick, Role role, Affiliation affiliation) : nick_(nick), role_(role), affiliation_(affiliation) {
}

MUCOccupant::~MUCOccupant() {
}

MUCOccupant::MUCOccupant(const MUCOccupant& other) : nick_(other.getNick()), role_(other.getRole()), affiliation_(other.getAffiliation()), realJID_(other.getRealJID()) {

}

MUCOccupant& MUCOccupant::operator=(MUCOccupant other) {
    std::swap(nick_, other.nick_);
    std::swap(role_, other.role_);
    std::swap(affiliation_, other.affiliation_);
    std::swap(realJID_, other.realJID_);
    return *this;
}

std::string MUCOccupant::getNick() const {
    return nick_;
}

MUCOccupant::Role MUCOccupant::getRole() const {
    return role_;
}

MUCOccupant::Affiliation MUCOccupant::getAffiliation() const {
    return affiliation_;
}

void MUCOccupant::setRealJID(const JID& realJID) {
    realJID_ = realJID;
}

void MUCOccupant::setNick(const std::string& nick) {
    nick_ = nick;
}


boost::optional<JID> MUCOccupant::getRealJID() const {
    return realJID_;
}

}
