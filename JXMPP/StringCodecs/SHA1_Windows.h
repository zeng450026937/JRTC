#ifndef JXMPP_SHA1_WINDOWS_H
#define JXMPP_SHA1_WINDOWS_H

#include <vector>
#include <Windows.h>
#define SECURITY_WIN32
#include <security.h>
#include <Wincrypt.h>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class JXMPP_API SHA1 {
        public:
            SHA1();
            ~SHA1();

            SHA1& update(const std::vector<unsigned char>& data);
            std::vector<unsigned char> getHash() const;

            static ByteArray getHash(const ByteArray& data);
            static ByteArray getHash(const SafeByteArray& data);

            ByteArray operator()(const SafeByteArray& data) {
                return getHash(data);
            }

            ByteArray operator()(const ByteArray& data) {
                return getHash(data);
            }

        private:
            SHA1& update(const unsigned char* data, size_t dataSize);

        private:
            HCRYPTHASH hash;
    };
}

#endif // JXMPP_SHA1_WINDOWS_H
