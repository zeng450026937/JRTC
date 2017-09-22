#ifndef JXMPP_PUBSUBEVENTPURGE_H
#define JXMPP_PUBSUBEVENTPURGE_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubEventPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubEventPurge : public PubSubEventPayload {
        public:

            PubSubEventPurge();

            virtual ~PubSubEventPurge();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }


        private:
            std::string node;
    };
}

#endif // JXMPP_PUBSUBEVENTPURGE_H
