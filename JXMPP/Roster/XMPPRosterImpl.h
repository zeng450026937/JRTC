#ifndef JXMPP_XMPPROSTERIMPL_H
#define JXMPP_XMPPROSTERIMPL_H

#include <map>
#include <set>

#include <JXMPP/Base/API.h>
#include <JXMPP/Roster/XMPPRoster.h>

namespace JXMPP {
    class JXMPP_API XMPPRosterImpl : public XMPPRoster {
        public:
            XMPPRosterImpl();
            virtual ~XMPPRosterImpl();

            void addContact(const JID& jid, const std::string& name, const std::vector<std::string>& groups, RosterItemPayload::Subscription subscription);
            void removeContact(const JID& jid);
            void clear();

            bool containsJID(const JID& jid);
            RosterItemPayload::Subscription getSubscriptionStateForJID(const JID& jid);
            std::string getNameForJID(const JID& jid) const;
            std::vector<std::string> getGroupsForJID(const JID& jid);

            virtual std::vector<XMPPRosterItem> getItems() const;
            virtual boost::optional<XMPPRosterItem> getItem(const JID&) const;
            virtual std::set<std::string> getGroups() const;

        private:
            typedef std::map<JID, XMPPRosterItem> RosterMap;
            RosterMap entries_;
    };
}

#endif // JXMPP_XMPPROSTERIMPL_H
