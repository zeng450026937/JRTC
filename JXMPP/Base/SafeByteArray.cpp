#include <JXMPP/Base/SafeByteArray.h>

using namespace JXMPP;

namespace JXMPP {

SafeByteArray createSafeByteArray(const char* c) {
    SafeByteArray data;
    while (*c) {
        data.push_back(static_cast<unsigned char>(*c));
        ++c;
    }
    return data;
}

}
