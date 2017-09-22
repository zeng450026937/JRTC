#ifndef JXMPP_PUBSUBEVENTREDIRECT_H
#define JXMPP_PUBSUBEVENTREDIRECT_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubEventRedirect : public Payload {
        public:

            PubSubEventRedirect();

            virtual ~PubSubEventRedirect();

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

#endif // JXMPP_PUBSUBEVENTREDIRECT_H
