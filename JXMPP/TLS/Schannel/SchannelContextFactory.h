#ifndef JXMPP_SCHANNELCONTEXTFACTORY_H
#define JXMPP_SCHANNELCONTEXTFACTORY_H

/*
 * Copyright (c) 2011 Soren Dreijer
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/TLS/TLSContextFactory.h>

namespace JXMPP {
    class SchannelContextFactory : public TLSContextFactory {
        public:
            SchannelContextFactory();

            bool canCreate() const;
            virtual TLSContext* createTLSContext(const TLSOptions& tlsOptions);

            virtual void setCheckCertificateRevocation(bool b);

            virtual void setDisconnectOnCardRemoval(bool b);

        public:
            bool checkCertificateRevocation;
            bool disconnectOnCardRemoval;
    };
}

#endif // JXMPP_SCHANNELCONTEXTFACTORY_H
