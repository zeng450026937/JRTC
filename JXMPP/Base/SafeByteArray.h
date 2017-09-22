#ifndef JXMPP_SAFEBYTEARRAY_H
#define JXMPP_SAFEBYTEARRAY_H

#include <memory>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Base/SafeAllocator.h>

namespace JXMPP {
    typedef std::vector<unsigned char, SafeAllocator<unsigned char> > SafeByteArray;

    inline SafeByteArray createSafeByteArray(const ByteArray& a) {
        return SafeByteArray(a.begin(), a.end());
    }

    JXMPP_API SafeByteArray createSafeByteArray(const char* c);

    inline SafeByteArray createSafeByteArray(const std::string& s) {
        return SafeByteArray(s.begin(), s.end());
    }

    inline std::shared_ptr<SafeByteArray> createSafeByteArrayRef(const std::string& s) {
        return std::make_shared<SafeByteArray>(s.begin(), s.end());
    }

    inline SafeByteArray createSafeByteArray(char c) {
        return SafeByteArray(1, static_cast<unsigned char>(c));
    }

    inline SafeByteArray createSafeByteArray(const char* c, size_t n) {
        return SafeByteArray(c, c + n);
    }

    inline std::shared_ptr<SafeByteArray> createSafeByteArrayRef(const char* c, size_t n) {
        return std::make_shared<SafeByteArray>(c, c + n);
    }

    inline SafeByteArray createSafeByteArray(const unsigned char* c, size_t n) {
        return SafeByteArray(c, c + n);
    }

    inline std::shared_ptr<SafeByteArray> createSafeByteArrayRef(const unsigned char* c, size_t n) {
        return std::make_shared<SafeByteArray>(c, c + n);
    }

    /* WARNING! This breaks the safety of the data in the safe byte array.
     * Do not use in modes that require data safety. */
    inline std::string safeByteArrayToString(const SafeByteArray& b) {
        return byteArrayToString(ByteArray(b.begin(), b.end()));
    }
}

#endif // JXMPP_SAFEBYTEARRAY_H
