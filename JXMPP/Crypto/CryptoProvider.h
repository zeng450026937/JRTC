#ifndef JXMPP_CRYPTOPROVIDER_H
#define JXMPP_CRYPTOPROVIDER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Crypto/Hash.h>

namespace JXMPP {
    class Hash;

    class JXMPP_API CryptoProvider {
        public:
            virtual ~CryptoProvider();

            virtual Hash* createSHA1() = 0;
            virtual Hash* createMD5() = 0;
            virtual ByteArray getHMACSHA1(const SafeByteArray& key, const ByteArray& data) = 0;
            virtual ByteArray getHMACSHA1(const ByteArray& key, const ByteArray& data) = 0;
            virtual bool isMD5AllowedForCrypto() const = 0;

            // Convenience
            template<typename T> ByteArray getSHA1Hash(const T& data) {
                return std::shared_ptr<Hash>(createSHA1())->update(data).getHash();
            }

            template<typename T> ByteArray getMD5Hash(const T& data) {
                return std::shared_ptr<Hash>(createMD5())->update(data).getHash();
            }
    };
}

#endif // JXMPP_CRYPTOPROVIDER_H
