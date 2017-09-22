#ifndef JXMPP_AVATARSTORAGE_H
#define JXMPP_AVATARSTORAGE_H

#include <string>

#include <boost/filesystem/path.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>

namespace JXMPP {
    class JID;

    class JXMPP_API AvatarStorage {
        public:
            virtual ~AvatarStorage();

            virtual bool hasAvatar(const std::string& hash) const = 0;
            virtual void addAvatar(const std::string& hash, const ByteArray& avatar) = 0;
            virtual ByteArray getAvatar(const std::string& hash) const = 0;
            virtual boost::filesystem::path getAvatarPath(const std::string& hash) const = 0;

            virtual void setAvatarForJID(const JID& jid, const std::string& hash) = 0;
            virtual std::string getAvatarForJID(const JID& jid) const = 0;
    };

}

#endif // JXMPP_AVATARSTORAGE_H
