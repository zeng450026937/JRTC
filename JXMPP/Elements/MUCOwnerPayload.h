#ifndef JXMPP_MUCOWNERPAYLOAD_H
#define JXMPP_MUCOWNERPAYLOAD_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Form.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API MUCOwnerPayload : public Payload {
        public:
            typedef std::shared_ptr<MUCOwnerPayload> ref;

            MUCOwnerPayload() {
            }

            std::shared_ptr<Payload> getPayload() const {
                return payload;
            }

            void setPayload(std::shared_ptr<Payload> p) {
                payload = p;
            }

            Form::ref getForm() {
                return std::dynamic_pointer_cast<Form>(payload);
            }

        private:
            std::shared_ptr<Payload> payload;
    };
}

#endif // JXMPP_MUCOWNERPAYLOAD_H
