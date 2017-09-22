#ifndef JXMPP_PLATFORMCRYPTOPROVIDER_H
#define JXMPP_PLATFORMCRYPTOPROVIDER_H

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class CryptoProvider;

    namespace PlatformCryptoProvider {
        JXMPP_API CryptoProvider* create();
    }
}

#endif // JXMPP_PLATFORMCRYPTOPROVIDER_H
