#ifndef JXMPP_AVATARMANAGER_H
#define JXMPP_AVATARMANAGER_H

#include <boost/filesystem/path.hpp>
#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>

namespace JXMPP {
    class JID;

    class JXMPP_API AvatarManager {
        public:
            virtual ~AvatarManager();

            virtual ByteArray getAvatar(const JID&) const = 0;
            virtual boost::filesystem::path getAvatarPath(const JID&) const = 0;

            boost::signals2::signal<void (const JID&)> onAvatarChanged;
    };
}

#endif // JXMPP_AVATARMANAGER_H
