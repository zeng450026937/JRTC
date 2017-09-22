#ifndef JXMPP_PUBSUBEVENTASSOCIATE_H
#define JXMPP_PUBSUBEVENTASSOCIATE_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubEventAssociate : public Payload {
        public:

            PubSubEventAssociate();

            virtual ~PubSubEventAssociate();

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

#endif // JXMPP_PUBSUBEVENTASSOCIATE_H
