/*
 * Copyright (c) 2011 Soren Dreijer
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/TLS/Schannel/SchannelContextFactory.h>

#include <JXMPP/TLS/Schannel/SchannelContext.h>

namespace JXMPP {

SchannelContextFactory::SchannelContextFactory() : checkCertificateRevocation(true), disconnectOnCardRemoval(true) {
}

bool SchannelContextFactory::canCreate() const {
    return true;
}

TLSContext* SchannelContextFactory::createTLSContext(const TLSOptions& tlsOptions) {
    SchannelContext* context = new SchannelContext(tlsOptions.schannelTLS1_0Workaround);
    context->setCheckCertificateRevocation(checkCertificateRevocation);
    context->setDisconnectOnCardRemoval(disconnectOnCardRemoval);
    return context;
}

void SchannelContextFactory::setCheckCertificateRevocation(bool b) {
    checkCertificateRevocation = b;
}

void SchannelContextFactory::setDisconnectOnCardRemoval(bool b) {
    disconnectOnCardRemoval = b;
}

}
