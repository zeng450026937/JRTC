#include <JXMPP/Roster/UnitTest/XMPPRosterSignalHandler.h>

#include <cassert>

#include <boost/bind.hpp>

using namespace JXMPP;

XMPPRosterSignalHandler::XMPPRosterSignalHandler(JXMPP::XMPPRoster* roster) : eventCount(0) {
    lastEvent_ = None;
    roster->onJIDAdded.connect(boost::bind(&XMPPRosterSignalHandler::handleJIDAdded, this, _1));
    roster->onJIDRemoved.connect(boost::bind(&XMPPRosterSignalHandler::handleJIDRemoved, this, _1));
    roster->onJIDUpdated.connect(boost::bind(&XMPPRosterSignalHandler::handleJIDUpdated, this, _1, _2, _3));
}

void XMPPRosterSignalHandler::handleJIDUpdated(const JXMPP::JID& jid, const std::string& oldName, const std::vector<std::string>& oldGroups) {
    assert(lastEvent_ == None);
    lastJID_ = jid;
    lastOldName_ = oldName;
    lastOldGroups_ = oldGroups;
    lastEvent_ = Update;
    eventCount++;
}
