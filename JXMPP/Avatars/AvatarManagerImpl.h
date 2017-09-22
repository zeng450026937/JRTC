#ifndef JXMPP_AVATARMANAGERIMPL_H
#define JXMPP_AVATARMANAGERIMPL_H

#include <JXMPP/Avatars/AvatarManager.h>
#include <JXMPP/Avatars/CombinedAvatarProvider.h>

namespace JXMPP {
    class MUCRegistry;
    class AvatarStorage;
    class StanzaChannel;
    class VCardManager;
    class VCardUpdateAvatarManager;
    class VCardAvatarManager;
    class OfflineAvatarManager;
    class CryptoProvider;

    class AvatarManagerImpl : public AvatarManager {
        public:
            AvatarManagerImpl(VCardManager*, StanzaChannel*, AvatarStorage*, CryptoProvider* crypto, MUCRegistry* = nullptr);
            virtual ~AvatarManagerImpl();

            virtual boost::filesystem::path getAvatarPath(const JID&) const;
            virtual ByteArray getAvatar(const JID&) const;

        private:
            void handleCombinedAvatarChanged(const JID& jid);


        private:
            CombinedAvatarProvider combinedAvatarProvider;
            AvatarStorage* avatarStorage;
            VCardUpdateAvatarManager* vcardUpdateAvatarManager;
            VCardAvatarManager* vcardAvatarManager;
            OfflineAvatarManager* offlineAvatarManager;
    };
}

#endif // JXMPP_AVATARMANAGERIMPL_H
