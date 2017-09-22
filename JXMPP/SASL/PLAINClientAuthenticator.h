#ifndef JXMPP_PLAINCLIENTAUTHENTICATOR_H
#define JXMPP_PLAINCLIENTAUTHENTICATOR_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/SASL/ClientAuthenticator.h>

namespace JXMPP {
    class JXMPP_API PLAINClientAuthenticator : public ClientAuthenticator {
        public:
            PLAINClientAuthenticator();

            virtual boost::optional<SafeByteArray> getResponse() const;
            virtual bool setChallenge(const boost::optional<ByteArray>&);
    };
}

#endif // JXMPP_PLAINCLIENTAUTHENTICATOR_H
