#ifndef JXMPP_NICKMANAGERIMPL_H
#define JXMPP_NICKMANAGERIMPL_H

#include <string>

#include <JXMPP/Client/NickManager.h>
#include <JXMPP/Elements/VCard.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class VCardManager;

    class NickManagerImpl : public NickManager {
        public:
            NickManagerImpl(const JID& ownJID, VCardManager* vcardManager);
            virtual ~NickManagerImpl();

            std::string getOwnNick() const;
            void setOwnNick(const std::string& nick);

        private:
            void handleVCardReceived(const JID& jid, VCard::ref vCard);
            void updateOwnNickFromVCard(VCard::ref vcard);

        private:
            JID ownJID;
            VCardManager* vcardManager;
            std::string ownNick;
    };
}

#endif // JXMPP_NICKMANAGERIMPL_H
