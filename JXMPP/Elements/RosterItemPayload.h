#ifndef JXMPP_ROSTERITEMPAYLOAD_H
#define JXMPP_ROSTERITEMPAYLOAD_H

#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API RosterItemPayload {
        public:
            enum Subscription { None, To, From, Both, Remove };

            RosterItemPayload() : subscription_(None), ask_(false) {}
            RosterItemPayload(const JID& jid, const std::string& name, Subscription subscription, const std::vector<std::string>& groups = std::vector<std::string>()) : jid_(jid), name_(name), subscription_(subscription), groups_(groups), ask_(false) { }

            void setJID(const JID& jid) { jid_ = jid; }
            const JID& getJID() const { return jid_; }

            void setName(const std::string& name) { name_ = name; }
            const std::string& getName() const { return name_; }

            void setSubscription(Subscription subscription) { subscription_ = subscription; }
            const Subscription& getSubscription() const { return subscription_; }

            void addGroup(const std::string& group) { groups_.push_back(group); }
            void setGroups(const std::vector<std::string>& groups) { groups_ = groups; }
            const std::vector<std::string>& getGroups() const { return groups_; }

            void setSubscriptionRequested() { ask_ = true; }
            bool getSubscriptionRequested() const { return ask_; }

            const std::string& getUnknownContent() const { return unknownContent_; }
            void addUnknownContent(const std::string& c) {
                unknownContent_ += c;
            }

        private:
            JID jid_;
            std::string name_;
            Subscription subscription_;
            std::vector<std::string> groups_;
            bool ask_;
            std::string unknownContent_;
    };
}

#endif // JXMPP_ROSTERITEMPAYLOAD_H
