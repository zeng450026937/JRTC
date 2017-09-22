#ifndef JXMPP_SERVERIDENTITYVERIFIER_H
#define JXMPP_SERVERIDENTITYVERIFIER_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/TLS/Certificate.h>

namespace JXMPP {
    class IDNConverter;

    class JXMPP_API ServerIdentityVerifier {
        public:
            ServerIdentityVerifier(const JID& jid, IDNConverter* idnConverter);

            bool certificateVerifies(Certificate::ref);

        private:
            bool matchesDomain(const std::string&) const ;
            bool matchesAddress(const std::string&) const;

        private:
            std::string domain;
            std::string encodedDomain;
            bool domainValid;
    };
}

#endif // JXMPP_SERVERIDENTITYVERIFIER_H
