#ifndef JXMPP_CLIENTERROR_H
#define JXMPP_CLIENTERROR_H

#include <memory>

#include <boost/system/system_error.hpp>

namespace JXMPP {
    class ClientError {
        public:
            enum Type {
                UnknownError,
                DomainNameResolveError,
                ConnectionError,
                ConnectionReadError,
                ConnectionWriteError,
                XMLError,
                AuthenticationFailedError,
                CompressionFailedError,
                ServerVerificationFailedError,
                NoSupportedAuthMechanismsError,
                UnexpectedElementError,
                ResourceBindError,
                SessionStartError,
                StreamError,
                TLSError,
                ClientCertificateLoadError,
                ClientCertificateError,

                // Certifate on smartcard was removed
                CertificateCardRemoved,

                // Certificate verification errors
                UnknownCertificateError,
                CertificateExpiredError,
                CertificateNotYetValidError,
                CertificateSelfSignedError,
                CertificateRejectedError,
                CertificateUntrustedError,
                InvalidCertificatePurposeError,
                CertificatePathLengthExceededError,
                InvalidCertificateSignatureError,
                InvalidCAError,
                InvalidServerIdentityError,
                RevokedError,
                RevocationCheckFailedError
            };

            ClientError(Type type = UnknownError) : type_(type) {}

            Type getType() const { return type_; }

            void setErrorCode(std::shared_ptr<boost::system::error_code> errorCode) { errorCode_ = errorCode; }

            std::shared_ptr<boost::system::error_code> getErrorCode() const { return errorCode_; }

        private:
            Type type_;
            std::shared_ptr<boost::system::error_code> errorCode_;
    };
}

#endif // JXMPP_CLIENTERROR_H
