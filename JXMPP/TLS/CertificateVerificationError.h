#ifndef JXMPP_CERTIFICATEVERIFICATIONERROR_H
#define JXMPP_CERTIFICATEVERIFICATIONERROR_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Error.h>

namespace JXMPP {
    class JXMPP_API CertificateVerificationError : public Error {
        public:
            typedef std::shared_ptr<CertificateVerificationError> ref;

            enum Type {
                UnknownError,
                Expired,
                NotYetValid,
                SelfSigned,
                Rejected,
                Untrusted,
                InvalidPurpose,
                PathLengthExceeded,
                InvalidSignature,
                InvalidCA,
                InvalidServerIdentity,
                Revoked,
                RevocationCheckFailed
            };

            CertificateVerificationError(Type type = UnknownError) : type(type) {}

            Type getType() const {
                return type;
            }

        private:
            Type type;
    };
}

#endif // JXMPP_CERTIFICATEVERIFICATIONERROR_H
