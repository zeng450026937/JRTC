#ifndef JXMPP_PBKDF2_H
#define JXMPP_PBKDF2_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Concat.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Crypto/CryptoProvider.h>

namespace JXMPP {
    class JXMPP_API PBKDF2 {
        public:
            static ByteArray encode(const SafeByteArray& password, const ByteArray& salt, int iterations, CryptoProvider* crypto) {
                ByteArray u = crypto->getHMACSHA1(password, concat(salt, createByteArray("\0\0\0\1", 4)));
                ByteArray result(u);
                int i = 1;
                while (i < iterations) {
                    u = crypto->getHMACSHA1(password, u);
                    for (unsigned int j = 0; j < u.size(); ++j) {
                        result[j] ^= u[j];
                    }
                    ++i;
                }
                return result;
            }
    };
}

#endif // JXMPP_PBKDF2_H
