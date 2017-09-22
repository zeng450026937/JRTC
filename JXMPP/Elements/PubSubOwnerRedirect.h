#ifndef JXMPP_PUBSUBOWNERREDIRECT_H
#define JXMPP_PUBSUBOWNERREDIRECT_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerRedirect : public Payload {
        public:

            PubSubOwnerRedirect();

            virtual ~PubSubOwnerRedirect();

            const std::string& getURI() const {
                return uri;
            }

            void setURI(const std::string& value) {
                this->uri = value ;
            }


        private:
            std::string uri;
    };
}

#endif // JXMPP_PUBSUBOWNERREDIRECT_H
