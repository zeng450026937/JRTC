#ifndef JXMPP_CLIENTAUTHENTICATOR_H
#define JXMPP_CLIENTAUTHENTICATOR_H

#include <string>
#include <vector>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class JXMPP_API ClientAuthenticator {
        public:
            ClientAuthenticator(const std::string& name);
            virtual ~ClientAuthenticator();

            const std::string& getName() const {
                return name;
            }

            void setCredentials(const std::string& authcid, const SafeByteArray& password, const std::string& authzid = std::string()) {
                this->authcid = authcid;
                this->password = password;
                this->authzid = authzid;
            }

            virtual boost::optional<SafeByteArray> getResponse() const = 0;
            virtual bool setChallenge(const boost::optional<ByteArray>&) = 0;

            const std::string& getAuthenticationID() const {
                return authcid;
            }

            const std::string& getAuthorizationID() const {
                return authzid;
            }

            const SafeByteArray& getPassword() const {
                return password;
            }

        private:
            std::string name;
            std::string authcid;
            SafeByteArray password;
            std::string authzid;
    };
}

#endif // JXMPP_CLIENTAUTHENTICATOR_H
