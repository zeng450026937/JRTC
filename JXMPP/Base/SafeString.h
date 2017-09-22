#ifndef JXMPP_SAFESTRING_H
#define JXMPP_SAFESTRING_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class JXMPP_API SafeString {
        public:
            SafeString(const SafeByteArray& data) : data(data) {
            }

            SafeString(const std::string& s) {
                data = createSafeByteArray(s);
            }

            SafeString(const char* s) {
                data = createSafeByteArray(s);
            }

            operator SafeByteArray () const {
                return data;
            }

        private:
            SafeByteArray data;
    };
}

#endif // JXMPP_SAFESTRING_H
