#ifndef JXMPP_PLAINMESSAGE_H
#define JXMPP_PLAINMESSAGE_H

// TODO: Get rid of this
//


#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/SafeByteArray.h>

namespace JXMPP {
    class JXMPP_API PLAINMessage {
        public:
            PLAINMessage(const std::string& authcid, const SafeByteArray& password, const std::string& authzid = "");
            PLAINMessage(const SafeByteArray& value);

            SafeByteArray getValue() const;

            const std::string& getAuthenticationID() const {
                return authcid;
            }

            const SafeByteArray& getPassword() const {
                return password;
            }

            const std::string& getAuthorizationID() const {
                return authzid;
            }

        private:
            std::string authcid;
            std::string authzid;
            SafeByteArray password;
    };
}

#endif // JXMPP_PLAINMESSAGE_H
