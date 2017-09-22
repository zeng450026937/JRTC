#ifndef JXMPP_VCARDAVATARMANAGER_H
#define JXMPP_VCARDAVATARMANAGER_H

#include <JXMPP/Avatars/AvatarProvider.h>
#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class MUCRegistry;
    class AvatarStorage;
    class VCardManager;
    class CryptoProvider;

    class JXMPP_API VCardAvatarManager : public AvatarProvider {
        public:
            VCardAvatarManager(VCardManager*, AvatarStorage*, CryptoProvider* crypto, MUCRegistry* = nullptr);

            boost::optional<std::string> getAvatarHash(const JID&) const;

        private:
            void handleVCardChanged(const JID& from);
            JID getAvatarJID(const JID& o) const;

        private:
            VCardManager* vcardManager_;
            AvatarStorage* avatarStorage_;
            CryptoProvider* crypto_;
            MUCRegistry* mucRegistry_;
    };
}

#endif // JXMPP_VCARDAVATARMANAGER_H
