#ifndef JXMPP_COMMONCRYPTOCRYPTOPROVIDER_H
#define JXMPP_COMMONCRYPTOCRYPTOPROVIDER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Crypto/CryptoProvider.h>

namespace JXMPP {
    class JXMPP_API CommonCryptoCryptoProvider : public CryptoProvider {
        public:
            CommonCryptoCryptoProvider();
            virtual ~CommonCryptoCryptoProvider() override;

            virtual Hash* createSHA1() override;
            virtual Hash* createMD5() override;
            virtual ByteArray getHMACSHA1(const SafeByteArray& key, const ByteArray& data) override;
            virtual ByteArray getHMACSHA1(const ByteArray& key, const ByteArray& data) override;
            virtual bool isMD5AllowedForCrypto() const override;
    };
}

#endif // JXMPP_COMMONCRYPTOCRYPTOPROVIDER_H
