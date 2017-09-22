#ifndef JXMPP_DUMMYAVATARMANAGER_H
#define JXMPP_DUMMYAVATARMANAGER_H

#include <map>

#include <JXMPP/Avatars/AvatarManager.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class DummyAvatarManager : public AvatarManager {
        public:
            virtual boost::filesystem::path getAvatarPath(const JID& j) const {
                return boost::filesystem::path("/avatars") / j.toString();
            }

            virtual ByteArray getAvatar(const JID& jid) const {
                std::map<JID, ByteArray>::const_iterator i = avatars.find(jid);
                if (i != avatars.end()) {
                    return i->second;
                }
                else {
                    return ByteArray();
                }
            }

            std::map<JID, ByteArray> avatars;
    };
}

#endif // JXMPP_DUMMYAVATARMANAGER_H
