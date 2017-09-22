#ifndef JXMPP_HASH_H
#define JXMPP_HASH_H

#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class JXMPP_API Hash {
        public:
            virtual ~Hash();

            virtual Hash& update(const ByteArray& data) = 0;
            virtual Hash& update(const SafeByteArray& data) = 0;

            virtual std::vector<unsigned char> getHash() = 0;
    };
}

#endif // JXMPP_HASH_H
