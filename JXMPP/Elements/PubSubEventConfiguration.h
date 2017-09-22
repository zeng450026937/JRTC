#ifndef JXMPP_PUBSUBEVENTCONFIGURATION_H
#define JXMPP_PUBSUBEVENTCONFIGURATION_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubEventPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubEventConfiguration : public PubSubEventPayload {
        public:

            PubSubEventConfiguration();

            virtual ~PubSubEventConfiguration();

            const std::string& getNode() const {
                return node;
            }

            void setNode(const std::string& value) {
                this->node = value ;
            }

            std::shared_ptr<Form> getData() const {
                return data;
            }

            void setData(std::shared_ptr<Form> value) {
                this->data = value ;
            }


        private:
            std::string node;
            std::shared_ptr<Form> data;
    };
}

#endif // JXMPP_PUBSUBEVENTCONFIGURATION_H
