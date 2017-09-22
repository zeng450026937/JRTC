#ifndef JXMPP_MUCDESTROYPAYLOADSERIALIZER_H
#define JXMPP_MUCDESTROYPAYLOADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCDestroyPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MUCDestroyPayloadSerializer : public GenericPayloadSerializer<MUCDestroyPayload> {
        public:
            MUCDestroyPayloadSerializer();
            virtual std::string serializePayload(std::shared_ptr<MUCDestroyPayload> version)  const;
    };
}

#endif // JXMPP_MUCDESTROYPAYLOADSERIALIZER_H
