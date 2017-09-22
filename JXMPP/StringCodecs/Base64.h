#ifndef JXMPP_BASE64_H
#define JXMPP_BASE64_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class JXMPP_API Base64 {
        public:
            static std::string encode(const ByteArray& s);
            static SafeByteArray encode(const SafeByteArray& s);

            static ByteArray decode(const std::string &s);
    };
}

#endif // JXMPP_BASE64_H
