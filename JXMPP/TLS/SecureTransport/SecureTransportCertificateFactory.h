#ifndef JXMPP_SECURETRANSPORTCERTIFICATEFACTORY_H
#define JXMPP_SECURETRANSPORTCERTIFICATEFACTORY_H

#include <JXMPP/TLS/CertificateFactory.h>
#include <JXMPP/TLS/SecureTransport/SecureTransportCertificate.h>

namespace JXMPP {

class SecureTransportCertificateFactory : public CertificateFactory {
    public:
        virtual Certificate* createCertificateFromDER(const ByteArray& der) {
            return new SecureTransportCertificate(der);
        }
    };
}

#endif // JXMPP_SECURETRANSPORTCERTIFICATEFACTORY_H
