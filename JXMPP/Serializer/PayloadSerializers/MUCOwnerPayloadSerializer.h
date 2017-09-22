#ifndef JXMPP_MUCOWNERPAYLOADSERIALIZER_H
#define JXMPP_MUCOWNERPAYLOADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCOwnerPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;
    class JXMPP_API MUCOwnerPayloadSerializer : public GenericPayloadSerializer<MUCOwnerPayload> {
        public:
            MUCOwnerPayloadSerializer(PayloadSerializerCollection* serializers);
            virtual std::string serializePayload(std::shared_ptr<MUCOwnerPayload> version)  const;
        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_MUCOWNERPAYLOADSERIALIZER_H
