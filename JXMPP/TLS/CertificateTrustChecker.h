#ifndef JXMPP_CERTIFICATETRUSTCHECKER_H
#define JXMPP_CERTIFICATETRUSTCHECKER_H

#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/TLS/Certificate.h>

namespace JXMPP {
    /**
     * A class to implement a check for certificate trust.
     */
    class JXMPP_API CertificateTrustChecker {
        public:
            virtual ~CertificateTrustChecker();

            /**
             * This method is called to find out whether a certificate (chain) is
             * trusted. This usually happens when a certificate's validation
             * fails, to check whether to proceed with the connection or not.
             *
             * certificateChain contains the chain of certificates. The first certificate
             * is the subject certificate.
             */
            virtual bool isCertificateTrusted(const std::vector<Certificate::ref>& certificateChain) = 0;
    };
}

#endif // JXMPP_CERTIFICATETRUSTCHECKER_H
