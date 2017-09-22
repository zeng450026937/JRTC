#ifndef JXMPP_PUBSUBCONFIGURE_H
#define JXMPP_PUBSUBCONFIGURE_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubConfigure : public Payload {
        public:

            PubSubConfigure();

            virtual ~PubSubConfigure();

            std::shared_ptr<Form> getData() const {
                return data;
            }

            void setData(std::shared_ptr<Form> value) {
                this->data = value ;
            }


        private:
            std::shared_ptr<Form> data;
    };
}

#endif // JXMPP_PUBSUBCONFIGURE_H
