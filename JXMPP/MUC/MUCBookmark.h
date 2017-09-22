#ifndef JXMPP_MUCBOOKMARK_H
#define JXMPP_MUCBOOKMARK_H

#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Storage.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API MUCBookmark {
        public:
            MUCBookmark(const Storage::Room& room) {
                name_ = room.name;
                room_ = room.jid;
                nick_ = room.nick;
                password_ = room.password;
                autojoin_ = room.autoJoin;
            }

            MUCBookmark(const JID& room, const std::string& bookmarkName) : room_(room), name_(bookmarkName), autojoin_(false) {
            }

            void setAutojoin(bool enabled) {
                autojoin_ = enabled;
            }

            bool getAutojoin() const {
                return autojoin_;
            }

            void setNick(const boost::optional<std::string>& nick) {
                nick_ = nick;
            }

            void setPassword(const boost::optional<std::string>& password) {
                password_ = password;
            }

            const boost::optional<std::string>& getNick() const {
                return nick_;
            }

            const boost::optional<std::string>& getPassword() const {
                return password_;
            }

            const std::string& getName() const {
                return name_;
            }

            const JID& getRoom() const {
                return room_;
            }

            bool operator==(const MUCBookmark& rhs) const {
                /* FIXME: not checking passwords for equality - which might make sense, perhaps */
                return rhs.room_ == room_ && rhs.name_ == name_ && rhs.nick_ == nick_ /*&& rhs.password_ == password_*/ && rhs.autojoin_ == autojoin_;
            }

            Storage::Room toStorage() const {
                Storage::Room room;
                room.name = name_;
                room.jid = room_;
                if (nick_) {
                    room.nick = *nick_;
                }
                if (password_) {
                    room.password = *password_;
                }
                room.autoJoin = autojoin_;
                return room;
            }

        private:
            JID room_;
            std::string name_;
            boost::optional<std::string> nick_;
            boost::optional<std::string> password_;
            bool autojoin_;
    };
}

#endif // JXMPP_MUCBOOKMARK_H
