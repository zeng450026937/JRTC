#ifndef JXMPP_OFFLINEAVATARMANAGER_H
#define JXMPP_OFFLINEAVATARMANAGER_H

#include <JXMPP/Avatars/AvatarProvider.h>
#include <JXMPP/Base/API.h>

namespace JXMPP {
    class AvatarStorage;

    class JXMPP_API OfflineAvatarManager : public AvatarProvider {
        public:
            OfflineAvatarManager(AvatarStorage*);
            ~OfflineAvatarManager();

            virtual boost::optional<std::string> getAvatarHash(const JID&) const;
            void setAvatar(const JID&, const std::string& hash);

        private:
            AvatarStorage* avatarStorage;
    };
}

#endif // JXMPP_OFFLINEAVATARMANAGER_H
