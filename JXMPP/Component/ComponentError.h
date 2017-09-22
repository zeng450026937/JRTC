#ifndef JXMPP_COMPONENTERROR_H
#define JXMPP_COMPONENTERROR_H

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API ComponentError {
        public:
            enum Type {
                UnknownError,
                ConnectionError,
                ConnectionReadError,
                ConnectionWriteError,
                XMLError,
                AuthenticationFailedError,
                UnexpectedElementError
            };

            ComponentError(Type type = UnknownError) : type_(type) {}

            Type getType() const { return type_; }

        private:
            Type type_;
    };
}

#endif // JXMPP_COMPONENTERROR_H
