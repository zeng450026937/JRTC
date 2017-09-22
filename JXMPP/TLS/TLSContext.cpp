#include <JXMPP/TLS/TLSContext.h>

namespace JXMPP {

TLSContext::~TLSContext() {
}

Certificate::ref TLSContext::getPeerCertificate() const {
    std::vector<Certificate::ref> chain = getPeerCertificateChain();
    return chain.empty() ? Certificate::ref() : chain[0];
}

}
