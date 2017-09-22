#ifndef JXMPP_AVATARPROVIDER_H
#define JXMPP_AVATARPROVIDER_H

#include <string>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JID;

    class JXMPP_API AvatarProvider {
        public:
            virtual ~AvatarProvider();

            virtual boost::optional<std::string> getAvatarHash(const JID&) const = 0;

            boost::signals2::signal<void (const JID&)> onAvatarChanged;
    };
}

#endif // JXMPP_AVATARPROVIDER_H
