#ifndef JXMPP_VCARDUPDATEAVATARMANAGER_H
#define JXMPP_VCARDUPDATEAVATARMANAGER_H

#include <map>
#include <memory>

#include <JXMPP/Avatars/AvatarProvider.h>
#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/Elements/VCard.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class MUCRegistry;
    class AvatarStorage;
    class StanzaChannel;
    class VCardManager;
    class CryptoProvider;

    class JXMPP_API VCardUpdateAvatarManager : public AvatarProvider, public boost::signals2::trackable {
        public:
            VCardUpdateAvatarManager(VCardManager*, StanzaChannel*, AvatarStorage*, CryptoProvider* crypto, MUCRegistry* = nullptr);

            boost::optional<std::string> getAvatarHash(const JID&) const;

        private:
            void handlePresenceReceived(std::shared_ptr<Presence>);
            void handleStanzaChannelAvailableChanged(bool);
            void handleVCardChanged(const JID& from, VCard::ref);
            void setAvatarHash(const JID& from, const std::string& hash);
            JID getAvatarJID(const JID& o) const;

        private:
            VCardManager* vcardManager_;
            AvatarStorage* avatarStorage_;
            CryptoProvider* crypto_;
            MUCRegistry* mucRegistry_;
            std::map<JID, std::string> avatarHashes_;
    };
}

#endif // JXMPP_VCARDUPDATEAVATARMANAGER_H
