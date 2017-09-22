#ifndef JXMPP_TLSCONTEXTFACTORY_H
#define JXMPP_TLSCONTEXTFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/TLS/TLSOptions.h>

namespace JXMPP {
    class TLSContext;

    class JXMPP_API TLSContextFactory {
        public:
            virtual ~TLSContextFactory();

            virtual bool canCreate() const = 0;

            virtual TLSContext* createTLSContext(const TLSOptions& tlsOptions) = 0;
            virtual void setCheckCertificateRevocation(bool b) = 0;
            virtual void setDisconnectOnCardRemoval(bool b) = 0;
    };
}

#endif // JXMPP_TLSCONTEXTFACTORY_H
