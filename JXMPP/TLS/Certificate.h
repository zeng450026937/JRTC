#ifndef JXMPP_CERTIFICATE_H
#define JXMPP_CERTIFICATE_H

#include <memory>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>

namespace JXMPP {
    class CryptoProvider;

    class JXMPP_API Certificate {
        public:
            typedef std::shared_ptr<Certificate> ref;

            virtual ~Certificate();

            /**
             * Returns the textual representation of the full Subject
             * name.
             */
            virtual std::string getSubjectName() const = 0;

            virtual std::vector<std::string> getCommonNames() const = 0;
            virtual std::vector<std::string> getSRVNames() const = 0;
            virtual std::vector<std::string> getDNSNames() const = 0;
            virtual std::vector<std::string> getXMPPAddresses() const = 0;

            virtual ByteArray toDER() const = 0;

            static std::string getSHA1Fingerprint(Certificate::ref, CryptoProvider* crypto);

        protected:
            static const char* ID_ON_XMPPADDR_OID;
            static const char* ID_ON_DNSSRV_OID;

    };
}

#endif // JXMPP_CERTIFICATE_H
