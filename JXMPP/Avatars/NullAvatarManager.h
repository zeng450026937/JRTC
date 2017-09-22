#ifndef JXMPP_NULLAVATARMANAGER_H
#define JXMPP_NULLAVATARMANAGER_H

#include <JXMPP/Avatars/AvatarManager.h>

namespace JXMPP {
    class NullAvatarManager : public AvatarManager {
        public:
            virtual boost::filesystem::path getAvatarPath(const JID&) const {
                return boost::filesystem::path();
            }

            virtual ByteArray getAvatar(const JID&) const {
                return ByteArray();
            }
    };
}

#endif // JXMPP_NULLAVATARMANAGER_H
