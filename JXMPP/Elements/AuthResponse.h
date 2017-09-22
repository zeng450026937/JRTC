#ifndef JXMPP_AUTHRESPONSE_H
#define JXMPP_AUTHRESPONSE_H

#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API AuthResponse : public ToplevelElement {
        public:
            AuthResponse() {
            }

            AuthResponse(const SafeByteArray& value) : value(value) {
            }

            AuthResponse(const boost::optional<SafeByteArray>& value) : value(value) {
            }

            const boost::optional<SafeByteArray>& getValue() const {
                return value;
            }

            void setValue(const SafeByteArray& value) {
                this->value = boost::optional<SafeByteArray>(value);
            }

        private:
            boost::optional<SafeByteArray> value;
    };
}

#endif // JXMPP_AUTHRESPONSE_H
