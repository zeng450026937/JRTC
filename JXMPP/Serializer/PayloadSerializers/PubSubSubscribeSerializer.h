#ifndef JXMPP_PUBSUBSUBSCRIBESERIALIZER_H
#define JXMPP_PUBSUBSUBSCRIBESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubSubscribe.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubSubscribeSerializer : public GenericPayloadSerializer<PubSubSubscribe> {
        public:
            PubSubSubscribeSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubSubscribeSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubSubscribe>) const override;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIBESERIALIZER_H
