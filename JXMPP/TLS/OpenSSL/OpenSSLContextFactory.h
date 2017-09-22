#ifndef JXMPP_OPENSSLCONTEXTFACTORY_H
#define JXMPP_OPENSSLCONTEXTFACTORY_H

#include <cassert>

#include <JXMPP/TLS/TLSContextFactory.h>

namespace JXMPP {
    class OpenSSLContextFactory : public TLSContextFactory {
        public:
            bool canCreate() const;
            virtual TLSContext* createTLSContext(const TLSOptions& tlsOptions);

            // Not supported
            virtual void setCheckCertificateRevocation(bool b);
            virtual void setDisconnectOnCardRemoval(bool b);
    };
}

#endif // JXMPP_OPENSSLCONTEXTFACTORY_H
