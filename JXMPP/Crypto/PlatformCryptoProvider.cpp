#include <JXMPP/Crypto/PlatformCryptoProvider.h>

#include <cassert>

#include <JXMPP/Base/Platform.h>
#if defined(JXMPP_PLATFORM_WIN32)
#include <JXMPP/Crypto/WindowsCryptoProvider.h>
#elif defined(HAVE_COMMONCRYPTO_CRYPTO_PROVIDER)
#include <JXMPP/Crypto/CommonCryptoCryptoProvider.h>
#elif defined(HAVE_OPENSSL_CRYPTO_PROVIDER)
#include <JXMPP/Crypto/OpenSSLCryptoProvider.h>
#endif

using namespace JXMPP;

CryptoProvider* PlatformCryptoProvider::create() {
#if defined(JXMPP_PLATFORM_WIN32)
    return new WindowsCryptoProvider();
#elif defined(HAVE_COMMONCRYPTO_CRYPTO_PROVIDER)
    return new CommonCryptoCryptoProvider();
#elif defined(HAVE_OPENSSL_CRYPTO_PROVIDER)
    return new OpenSSLCryptoProvider();
#endif
    assert(false);
    return nullptr;
}
