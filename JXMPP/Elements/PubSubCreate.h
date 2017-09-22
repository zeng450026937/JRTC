#ifndef JXMPP_PUBSUBCREATE_H
#define JXMPP_PUBSUBCREATE_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubConfigure.h>
#include <JXMPP/Elements/PubSubPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubCreate : public PubSubPayload {
        public:

            PubSubCreate();
            PubSubCreate(const std::string& node) : node(node) {}
            virtual ~PubSubCreate();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            std::shared_ptr<PubSubConfigure> getConfigure() const {
                return configure;
            }

            void setConfigure(std::shared_ptr<PubSubConfigure> value) {
                this->configure = value ;
            }


        private:
            std::string node;
            std::shared_ptr<PubSubConfigure> configure;
    };
}

#endif // JXMPP_PUBSUBCREATE_H
