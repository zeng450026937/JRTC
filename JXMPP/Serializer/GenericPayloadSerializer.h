#ifndef JXMPP_GENERICPAYLOADSERIALIZER_H
#define JXMPP_GENERICPAYLOADSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Serializer/PayloadSerializer.h>

namespace JXMPP {
    template<typename PAYLOAD_TYPE>
    class GenericPayloadSerializer : public PayloadSerializer {
        public:
            virtual std::string serialize(std::shared_ptr<Payload> element)  const {
                return serializePayload(std::dynamic_pointer_cast<PAYLOAD_TYPE>(element));
            }

            virtual bool canSerialize(std::shared_ptr<Payload> element) const {
                return !!std::dynamic_pointer_cast<PAYLOAD_TYPE>(element);
            }

            virtual std::string serializePayload(std::shared_ptr<PAYLOAD_TYPE>) const = 0;
    };
}

#endif // JXMPP_GENERICPAYLOADSERIALIZER_H
