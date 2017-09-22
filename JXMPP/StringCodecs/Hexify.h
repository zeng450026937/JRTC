#ifndef JXMPP_HEXIFY_H
#define JXMPP_HEXIFY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>

namespace JXMPP {
    class JXMPP_API Hexify {
        public:
            static std::string hexify(unsigned char byte);
            static std::string hexify(const ByteArray& data);
            static ByteArray unhexify(const std::string& hexstring);
    };
}

#endif // JXMPP_HEXIFY_H
