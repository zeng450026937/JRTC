#ifndef JXMPP_PUBSUBEVENTDISASSOCIATE_H
#define JXMPP_PUBSUBEVENTDISASSOCIATE_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubEventDisassociate : public Payload {
        public:

            PubSubEventDisassociate();

            virtual ~PubSubEventDisassociate();

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

#endif // JXMPP_PUBSUBEVENTDISASSOCIATE_H
