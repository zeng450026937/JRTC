#ifndef JXMPP_XMPPROSTERSIGNALHANDLER_H
#define JXMPP_XMPPROSTERSIGNALHANDLER_H

#include <memory>
#include <vector>

#include <JXMPP/Roster/XMPPRosterImpl.h>

enum XMPPRosterEvents {None, Add, Remove, Update};

class XMPPRosterSignalHandler {
public:
    XMPPRosterSignalHandler(JXMPP::XMPPRoster* roster);

    XMPPRosterEvents getLastEvent() {
        return lastEvent_;
    }

    JXMPP::JID getLastJID() {
        return lastJID_;
    }

    std::string getLastOldName() {
        return lastOldName_;
    }

    std::vector<std::string> getLastOldGroups() {
        return lastOldGroups_;
    }

    void reset() {
        lastEvent_ = None;
    }

    int getEventCount() const {
        return eventCount;
    }

private:
    void handleJIDAdded(const JXMPP::JID& jid) {
        lastJID_ = jid;
        lastEvent_ = Add;
        eventCount++;
    }

    void handleJIDRemoved(const JXMPP::JID& jid) {
        lastJID_ = jid;
        lastEvent_ = Remove;
        eventCount++;
    }

    void handleJIDUpdated(const JXMPP::JID& jid, const std::string& oldName, const std::vector<std::string>& oldGroups);

    XMPPRosterEvents lastEvent_;
    JXMPP::JID lastJID_;
    std::string lastOldName_;
    std::vector<std::string> lastOldGroups_;
    int eventCount;
};

#endif // JXMPP_XMPPROSTERSIGNALHANDLER_H
