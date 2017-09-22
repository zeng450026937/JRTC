#ifndef JXMPP_CERTIFICATEFACTORY_H
#define JXMPP_CERTIFICATEFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/TLS/Certificate.h>

namespace JXMPP {
    class JXMPP_API CertificateFactory {
        public:
            virtual ~CertificateFactory();

            virtual Certificate* createCertificateFromDER(const ByteArray& der) = 0;
    };
}

#endif // JXMPP_CERTIFICATEFACTORY_H
