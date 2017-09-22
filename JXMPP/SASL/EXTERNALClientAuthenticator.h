#ifndef JXMPP_EXTERNALCLIENTAUTHENTICATOR_H
#define JXMPP_EXTERNALCLIENTAUTHENTICATOR_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/SASL/ClientAuthenticator.h>

namespace JXMPP {
    class JXMPP_API EXTERNALClientAuthenticator : public ClientAuthenticator {
        public:
            EXTERNALClientAuthenticator();

            virtual boost::optional<SafeByteArray> getResponse() const;
            virtual bool setChallenge(const boost::optional<ByteArray>&);

        private:
            bool finished;
    };
}

#endif // JXMPP_EXTERNALCLIENTAUTHENTICATOR_H
