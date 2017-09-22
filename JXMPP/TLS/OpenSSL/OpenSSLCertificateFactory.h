#ifndef JXMPP_OPENSSLCERTIFICATEFACTORY_H
#define JXMPP_OPENSSLCERTIFICATEFACTORY_H

#include <JXMPP/TLS/CertificateFactory.h>
#include <JXMPP/TLS/OpenSSL/OpenSSLCertificate.h>

namespace JXMPP {
    class OpenSSLCertificateFactory : public CertificateFactory {
        public:
            virtual Certificate* createCertificateFromDER(const ByteArray& der) {
                return new OpenSSLCertificate(der);
            }
    };
}

#endif // JXMPP_OPENSSLCERTIFICATEFACTORY_H
