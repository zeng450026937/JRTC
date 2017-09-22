#ifndef JXMPP_JINGLETRANSPORTPAYLOAD_H
#define JXMPP_JINGLETRANSPORTPAYLOAD_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API JingleTransportPayload : public Payload {
        public:
            void setSessionID(const std::string& id) {
                sessionID = id;
            }

            const std::string& getSessionID() const {
                return sessionID;
            }

        public:
            typedef std::shared_ptr<JingleTransportPayload> ref;

        private:
            std::string sessionID;
    };
}

#endif // JXMPP_JINGLETRANSPORTPAYLOAD_H
