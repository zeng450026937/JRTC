#ifndef JXMPP_COMPONENTHANDSHAKEGENERATOR_H
#define JXMPP_COMPONENTHANDSHAKEGENERATOR_H

#include <string>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class CryptoProvider;

    class JXMPP_API ComponentHandshakeGenerator {
        public:
            static std::string getHandshake(const std::string& streamID, const std::string& secret, CryptoProvider* crypto);
    };

}

#endif // JXMPP_COMPONENTHANDSHAKEGENERATOR_H
