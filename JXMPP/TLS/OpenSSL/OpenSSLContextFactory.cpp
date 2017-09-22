#include <JXMPP/TLS/OpenSSL/OpenSSLContextFactory.h>

#include <JXMPP/Base/Log.h>
#include <JXMPP/TLS/OpenSSL/OpenSSLContext.h>

namespace JXMPP {

bool OpenSSLContextFactory::canCreate() const {
    return true;
}

TLSContext* OpenSSLContextFactory::createTLSContext(const TLSOptions&) {
    return new OpenSSLContext();
}

void OpenSSLContextFactory::setCheckCertificateRevocation(bool check) {
    if (check) {
        JXMPP_LOG(warning) << "CRL Checking not supported for OpenSSL" << std::endl;
        assert(false);
    }
}

void OpenSSLContextFactory::setDisconnectOnCardRemoval(bool check) {
    if (check) {
        JXMPP_LOG(warning) << "Smart cards not supported for OpenSSL" << std::endl;
    }
}



}
