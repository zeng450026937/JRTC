#ifndef JXMPP_AVATARMEMORYSTORAGE_H
#define JXMPP_AVATARMEMORYSTORAGE_H

#include <map>
#include <string>

#include <JXMPP/Avatars/AvatarStorage.h>
#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API AvatarMemoryStorage : public AvatarStorage {
        public:
            virtual bool hasAvatar(const std::string& hash) const { return avatars.find(hash) != avatars.end(); }
            virtual void addAvatar(const std::string& hash, const ByteArray& avatar) { avatars[hash] = avatar; }
            virtual ByteArray getAvatar(const std::string& hash) const {
                std::map<std::string, ByteArray>::const_iterator i = avatars.find(hash);
                return i == avatars.end() ? ByteArray() : i->second;
            }

            virtual boost::filesystem::path getAvatarPath(const std::string& hash) const {
                return boost::filesystem::path("/avatars") / hash;
            }

            virtual void setAvatarForJID(const JID& jid, const std::string& hash) {
                jidAvatars[jid] = hash;
            }

            virtual std::string getAvatarForJID(const JID& jid) const {
                std::map<JID, std::string>::const_iterator i = jidAvatars.find(jid);
                return i == jidAvatars.end() ? "" : i->second;
            }

        private:
            std::map<std::string, ByteArray> avatars;
            std::map<JID, std::string> jidAvatars;
    };
}

#endif // JXMPP_AVATARMEMORYSTORAGE_H
