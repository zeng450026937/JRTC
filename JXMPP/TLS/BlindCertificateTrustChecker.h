#ifndef JXMPP_BLINDCERTIFICATETRUSTCHECKER_H
#define JXMPP_BLINDCERTIFICATETRUSTCHECKER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/TLS/CertificateTrustChecker.h>

namespace JXMPP {
    /**
     * A certificate trust checker that trusts any ceritficate.
     *
     * This can be used to ignore any TLS certificate errors occurring
     * during connection.
     *
     * \see Client::setAlwaysTrustCertificates()
     */
    class JXMPP_API BlindCertificateTrustChecker : public CertificateTrustChecker {
        public:
            virtual bool isCertificateTrusted(const std::vector<Certificate::ref>&) {
                return true;
            }
    };
}

#endif // JXMPP_BLINDCERTIFICATETRUSTCHECKER_H
