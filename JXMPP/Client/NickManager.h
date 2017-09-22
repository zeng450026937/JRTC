#ifndef JXMPP_NICKMANAGER_H
#define JXMPP_NICKMANAGER_H

#include <string>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API NickManager {
        public:
            virtual ~NickManager();

            virtual std::string getOwnNick() const = 0;
            virtual void setOwnNick(const std::string& nick) = 0;

            boost::signals2::signal<void (const std::string&)> onOwnNickChanged;
    };
}

#endif // JXMPP_NICKMANAGER_H
