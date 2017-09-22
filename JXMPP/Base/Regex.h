#ifndef JXMPP_REGEX_H
#define JXMPP_REGEX_H

#include <string>

#include <JXMPP/Base/API.h>

namespace JXMPP {

    namespace Regex {
        JXMPP_API std::string escape(const std::string& source);
    }

}

#endif // JXMPP_REGEX_H
