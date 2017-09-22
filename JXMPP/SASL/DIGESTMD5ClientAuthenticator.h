#ifndef JXMPP_DIGESTMD5CLIENTAUTHENTICATOR_H
#define JXMPP_DIGESTMD5CLIENTAUTHENTICATOR_H

#include <map>
#include <string>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/SASL/ClientAuthenticator.h>
#include <JXMPP/SASL/DIGESTMD5Properties.h>

namespace JXMPP {
    class CryptoProvider;

    class JXMPP_API DIGESTMD5ClientAuthenticator : public ClientAuthenticator {
        public:
            DIGESTMD5ClientAuthenticator(const std::string& host, const std::string& nonce, CryptoProvider*);

            virtual boost::optional<SafeByteArray> getResponse() const;
            virtual bool setChallenge(const boost::optional<std::vector<unsigned char> >&);

        private:
            enum Step {
                Initial,
                Response,
                Final
            } step;
            std::string host;
            std::string cnonce;
            CryptoProvider* crypto;
            DIGESTMD5Properties challenge;
    };
}

#endif // JXMPP_DIGESTMD5CLIENTAUTHENTICATOR_H
