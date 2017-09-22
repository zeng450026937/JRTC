#ifndef JXMPP_DUMMYNICKMANAGER_H
#define JXMPP_DUMMYNICKMANAGER_H

#include <JXMPP/Client/NickManager.h>

namespace JXMPP {
    class DummyNickManager : public NickManager {
        public:
            std::string getOwnNick() const {
                return "";
            }

            void setOwnNick(const std::string&) {
            }
    };
}

#endif // JXMPP_DUMMYNICKMANAGER_H
