#ifndef JXMPP_TLSERROR_H
#define JXMPP_TLSERROR_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Error.h>

namespace JXMPP {
    class JXMPP_API TLSError : public Error {
        public:
            typedef std::shared_ptr<TLSError> ref;

            enum Type {
                UnknownError,
                CertificateCardRemoved
            };

            TLSError(Type type = UnknownError) : type(type) {}

            Type getType() const {
                return type;
            }

        private:
            Type type;
    };
}

#endif // JXMPP_TLSERROR_H
