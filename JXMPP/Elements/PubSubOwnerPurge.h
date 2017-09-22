#ifndef JXMPP_PUBSUBOWNERPURGE_H
#define JXMPP_PUBSUBOWNERPURGE_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubOwnerPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerPurge : public PubSubOwnerPayload {
        public:

            PubSubOwnerPurge();

            virtual ~PubSubOwnerPurge();

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

#endif // JXMPP_PUBSUBOWNERPURGE_H
