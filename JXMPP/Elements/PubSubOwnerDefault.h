#ifndef JXMPP_PUBSUBOWNERDEFAULT_H
#define JXMPP_PUBSUBOWNERDEFAULT_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubOwnerPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerDefault : public PubSubOwnerPayload {
        public:

            PubSubOwnerDefault();

            virtual ~PubSubOwnerDefault();

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

#endif // JXMPP_PUBSUBOWNERDEFAULT_H
