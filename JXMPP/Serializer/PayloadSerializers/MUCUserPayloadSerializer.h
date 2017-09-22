#ifndef JXMPP_MUCUSERPAYLOADSERIALIZER_H
#define JXMPP_MUCUSERPAYLOADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCUserPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;
    class JXMPP_API MUCUserPayloadSerializer : public GenericPayloadSerializer<MUCUserPayload> {
        public:
            MUCUserPayloadSerializer(PayloadSerializerCollection* serializers);

            virtual std::string serializePayload(std::shared_ptr<MUCUserPayload> version)  const;
        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_MUCUSERPAYLOADSERIALIZER_H
