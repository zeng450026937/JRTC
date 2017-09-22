#ifndef JXMPP_XMPPROSTERITEM_H
#define JXMPP_XMPPROSTERITEM_H

#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RosterItemPayload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API XMPPRosterItem {
        public:
            XMPPRosterItem(const JID& jid, const std::string& name, const std::vector<std::string>& groups, RosterItemPayload::Subscription subscription) : jid(jid), name(name), groups(groups), subscription(subscription) {
            }

            const JID& getJID() const {
                return jid;
            }

            const std::string& getName() const {
                return name;
            }

            void setName(const std::string& name) {
                this->name = name;
            }

            const std::vector<std::string>& getGroups() const {
                return groups;
            }

            void setGroups(const std::vector<std::string>& groups) {
                this->groups = groups;
            }

            RosterItemPayload::Subscription getSubscription() const {
                return subscription;
            }

        private:
            JID jid;
            std::string name;
            std::vector<std::string> groups;
            RosterItemPayload::Subscription subscription;
    };
}

#endif // JXMPP_XMPPROSTERITEM_H
