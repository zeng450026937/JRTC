#ifndef JXMPP_MUCPAYLOADSERIALIZER_H
#define JXMPP_MUCPAYLOADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MUCPayloadSerializer : public GenericPayloadSerializer<MUCPayload> {
        public:
            MUCPayloadSerializer();
            virtual std::string serializePayload(std::shared_ptr<MUCPayload> version)  const;
    };
}

#endif // JXMPP_MUCPAYLOADSERIALIZER_H
