#include <JXMPP/TLS/PlatformTLSFactories.h>

#include <JXMPP/Base/Platform.h>
#include <JXMPP/TLS/CertificateFactory.h>
#include <JXMPP/TLS/TLSContextFactory.h>
#ifdef HAVE_OPENSSL
    #include <JXMPP/TLS/OpenSSL/OpenSSLContextFactory.h>
    #include <JXMPP/TLS/OpenSSL/OpenSSLCertificateFactory.h>
#endif
#ifdef HAVE_SCHANNEL
    #include <JXMPP/TLS/Schannel/SchannelContextFactory.h>
    #include <JXMPP/TLS/Schannel/SchannelCertificateFactory.h>
#endif
#ifdef HAVE_SECURETRANSPORT
    #include <JXMPP/TLS/SecureTransport/SecureTransportContextFactory.h>
    #include <JXMPP/TLS/SecureTransport/SecureTransportCertificateFactory.h>
#endif

namespace JXMPP {

PlatformTLSFactories::PlatformTLSFactories() : contextFactory(nullptr), certificateFactory(nullptr) {
#ifdef HAVE_OPENSSL
    contextFactory = new OpenSSLContextFactory();
    certificateFactory = new OpenSSLCertificateFactory();
#endif
#ifdef HAVE_SCHANNEL
    contextFactory = new SchannelContextFactory();
    certificateFactory = new SchannelCertificateFactory();
#endif
#ifdef HAVE_SECURETRANSPORT
    contextFactory = new SecureTransportContextFactory();
    certificateFactory = new SecureTransportCertificateFactory();
#endif
}

PlatformTLSFactories::~PlatformTLSFactories() {
    delete contextFactory;
    delete certificateFactory;
}

TLSContextFactory* PlatformTLSFactories::getTLSContextFactory() const {
    return contextFactory;
}

CertificateFactory* PlatformTLSFactories::getCertificateFactory() const {
    return certificateFactory;
}

}
