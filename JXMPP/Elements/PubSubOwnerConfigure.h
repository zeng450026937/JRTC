#ifndef JXMPP_PUBSUBOWNERCONFIGURE_H
#define JXMPP_PUBSUBOWNERCONFIGURE_H

#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubOwnerPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerConfigure : public PubSubOwnerPayload {
        public:

            PubSubOwnerConfigure();
            PubSubOwnerConfigure(const std::string& node) : node(node) {}
            virtual ~PubSubOwnerConfigure();

            const boost::optional< std::string >& getNode() const {
                return node;
            }

            void setNode(const boost::optional< std::string >& value) {
                this->node = value ;
            }

            std::shared_ptr<Form> getData() const {
                return data;
            }

            void setData(std::shared_ptr<Form> value) {
                this->data = value ;
            }


        private:
            boost::optional< std::string > node;
            std::shared_ptr<Form> data;
    };
}

#endif // JXMPP_PUBSUBOWNERCONFIGURE_H
