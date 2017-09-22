#ifndef JXMPP_NICKRESOLVER_H
#define JXMPP_NICKRESOLVER_H

#include <map>
#include <memory>
#include <string>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/VCard.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class XMPPRoster;
    class MUCRegistry;
    class VCardManager;

    class JXMPP_API NickResolver {
        public:
            NickResolver(const JID& ownJID, XMPPRoster* xmppRoster, VCardManager* vcardManager, MUCRegistry* mucRegistry);

            std::string jidToNick(const JID& jid);

            boost::signals2::signal<void (const JID&, const std::string& /*previousNick*/)> onNickChanged;

        private:
            void handleVCardReceived(const JID& jid, VCard::ref vCard);
            void handleJIDUpdated(const JID& jid, const std::string& previousNick, const std::vector<std::string>& groups);
            void handleJIDAdded(const JID& jid);

        private:
            JID ownJID_;
            std::string ownNick_;
            XMPPRoster* xmppRoster_;
            MUCRegistry* mucRegistry_;
            VCardManager* vcardManager_;
    };
}

#endif // JXMPP_NICKRESOLVER_H
