#ifndef JXMPP_SCHANNELCERTIFICATEFACTORY_H
#define JXMPP_SCHANNELCERTIFICATEFACTORY_H

/*
 * Copyright (c) 2011 Soren Dreijer
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/TLS/CertificateFactory.h>
#include <JXMPP/TLS/Schannel/SchannelCertificate.h>

namespace JXMPP {
    class SchannelCertificateFactory : public CertificateFactory {
        public:
            virtual Certificate* createCertificateFromDER(const ByteArray& der) {
                return new SchannelCertificate(der);
            }
    };
}

#endif // JXMPP_SCHANNELCERTIFICATEFACTORY_H
