#ifndef JXMPP_NICKNAME_H
#define JXMPP_NICKNAME_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API Nickname : public Payload {
        public:
            Nickname(const std::string& nickname = "") : nickname(nickname) {
            }

            void setNickname(const std::string& nickname) {
                this->nickname = nickname;
            }

            const std::string& getNickname() const {
                return nickname;
            }

        private:
            std::string nickname;
    };
}

#endif // JXMPP_NICKNAME_H
