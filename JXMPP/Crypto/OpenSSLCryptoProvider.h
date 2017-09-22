#ifndef JXMPP_OPENSSLCRYPTOPROVIDER_H
#define JXMPP_OPENSSLCRYPTOPROVIDER_H

#include <JXMPP/Crypto/CryptoProvider.h>

namespace JXMPP {
    class OpenSSLCryptoProvider : public CryptoProvider {
        public:
            OpenSSLCryptoProvider();
            virtual ~OpenSSLCryptoProvider() override;

            virtual Hash* createSHA1() override;
            virtual Hash* createMD5() override;
            virtual ByteArray getHMACSHA1(const SafeByteArray& key, const ByteArray& data) override;
            virtual ByteArray getHMACSHA1(const ByteArray& key, const ByteArray& data) override;
            virtual bool isMD5AllowedForCrypto() const override;
    };
}

#endif // JXMPP_OPENSSLCRYPTOPROVIDER_H
