#ifndef JXMPP_CERTIFICATEWITHKEY_H
#define JXMPP_CERTIFICATEWITHKEY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class JXMPP_API CertificateWithKey {
        public:
            typedef std::shared_ptr<CertificateWithKey> ref;
            CertificateWithKey() {}

            virtual ~CertificateWithKey() {}

            virtual bool isNull() const = 0;

    };
}

#endif // JXMPP_CERTIFICATEWITHKEY_H
