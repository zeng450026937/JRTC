#ifndef JXMPP_PUBSUBSUBSCRIBEOPTIONS_H
#define JXMPP_PUBSUBSUBSCRIBEOPTIONS_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubSubscribeOptions : public Payload {
        public:

            PubSubSubscribeOptions();

            virtual ~PubSubSubscribeOptions();

            bool isRequired() const {
                return required;
            }

            void setRequired(bool value) {
                this->required = value ;
            }


        private:
            bool required;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIBEOPTIONS_H
