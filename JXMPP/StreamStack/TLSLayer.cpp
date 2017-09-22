#include <JXMPP/StreamStack/TLSLayer.h>

#include <boost/bind.hpp>

#include <JXMPP/TLS/TLSContext.h>
#include <JXMPP/TLS/TLSContextFactory.h>

namespace JXMPP {

TLSLayer::TLSLayer(TLSContextFactory* factory, const TLSOptions& tlsOptions) {
    context = factory->createTLSContext(tlsOptions);
    context->onDataForNetwork.connect(boost::bind(&TLSLayer::writeDataToChildLayer, this, _1));
    context->onDataForApplication.connect(boost::bind(&TLSLayer::writeDataToParentLayer, this, _1));
    context->onConnected.connect(onConnected);
    context->onError.connect(onError);
}

TLSLayer::~TLSLayer() {
    delete context;
}

void TLSLayer::connect() {
    context->connect();
}

void TLSLayer::writeData(const SafeByteArray& data) {
    context->handleDataFromApplication(data);
}

void TLSLayer::handleDataRead(const SafeByteArray& data) {
    context->handleDataFromNetwork(data);
}

bool TLSLayer::setClientCertificate(CertificateWithKey::ref certificate) {
    return context->setClientCertificate(certificate);
}

Certificate::ref TLSLayer::getPeerCertificate() const {
    return context->getPeerCertificate();
}

std::vector<Certificate::ref> TLSLayer::getPeerCertificateChain() const {
    return context->getPeerCertificateChain();
}

std::shared_ptr<CertificateVerificationError> TLSLayer::getPeerCertificateVerificationError() const {
    return context->getPeerCertificateVerificationError();
}

}
