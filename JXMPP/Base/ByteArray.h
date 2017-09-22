#ifndef JXMPP_BYTEARRAY_H
#define JXMPP_BYTEARRAY_H

#include <string>
#include <vector>

#include <boost/filesystem/path.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    typedef std::vector<unsigned char> ByteArray;

    JXMPP_API ByteArray createByteArray(const std::string& s);
    JXMPP_API ByteArray createByteArray(const char* c);

    inline ByteArray createByteArray(const unsigned char* c, size_t n) {
        return ByteArray(c, c  + n);
    }

    inline ByteArray createByteArray(const char* c, size_t n) {
        return ByteArray(c, c  + n);
    }

    inline ByteArray createByteArray(char c) {
        return std::vector<unsigned char>(1, static_cast<unsigned char>(c));
    }

    template<typename T, typename A>
    static const T* vecptr(const std::vector<T, A>& v) {
        return v.empty() ? nullptr : &v[0];
    }

    template<typename T, typename A>
    static T* vecptr(std::vector<T, A>& v) {
        return v.empty() ? nullptr : &v[0];
    }

    JXMPP_API std::string byteArrayToString(const ByteArray& b);

    JXMPP_API void readByteArrayFromFile(ByteArray&, const boost::filesystem::path& file);
}

#endif // JXMPP_BYTEARRAY_H
