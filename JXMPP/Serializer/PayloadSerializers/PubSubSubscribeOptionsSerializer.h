#ifndef JXMPP_PUBSUBSUBSCRIBEOPTIONSSERIALIZER_H
#define JXMPP_PUBSUBSUBSCRIBEOPTIONSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubSubscribeOptions.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubSubscribeOptionsSerializer : public GenericPayloadSerializer<PubSubSubscribeOptions> {
        public:
            PubSubSubscribeOptionsSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubSubscribeOptionsSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubSubscribeOptions>) const override;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIBEOPTIONSSERIALIZER_H
