#ifndef JXMPP_SECURETRANSPORTCONTEXTFACTORY_H
#define JXMPP_SECURETRANSPORTCONTEXTFACTORY_H

#include <JXMPP/TLS/TLSContextFactory.h>

namespace JXMPP {

class SecureTransportContextFactory : public TLSContextFactory {
    public:
        SecureTransportContextFactory();
        virtual ~SecureTransportContextFactory();

        virtual bool canCreate() const;

        virtual TLSContext* createTLSContext(const TLSOptions& tlsOptions);
        virtual void setCheckCertificateRevocation(bool b);
        virtual void setDisconnectOnCardRemoval(bool b);

    private:
        bool checkCertificateRevocation_;
        bool disconnectOnCardRemoval_;
};

}

#endif // JXMPP_SECURETRANSPORTCONTEXTFACTORY_H
