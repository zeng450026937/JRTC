#ifndef JXMPP_PLATFORMTLSFACTORIES_H
#define JXMPP_PLATFORMTLSFACTORIES_H

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class TLSContextFactory;
    class CertificateFactory;

    class JXMPP_API PlatformTLSFactories {
        public:
            PlatformTLSFactories();
            ~PlatformTLSFactories();

            TLSContextFactory* getTLSContextFactory() const;
            CertificateFactory* getCertificateFactory() const;

        private:
            TLSContextFactory* contextFactory;
            CertificateFactory* certificateFactory;
    };
}

#endif // JXMPP_PLATFORMTLSFACTORIES_H
