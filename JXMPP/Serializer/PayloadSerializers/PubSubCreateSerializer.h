#ifndef JXMPP_PUBSUBCREATESERIALIZER_H
#define JXMPP_PUBSUBCREATESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubCreate.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubCreateSerializer : public GenericPayloadSerializer<PubSubCreate> {
        public:
            PubSubCreateSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubCreateSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubCreate>) const override;
    };
}

#endif // JXMPP_PUBSUBCREATESERIALIZER_H
