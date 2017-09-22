#ifndef JXMPP_PUBSUBOPTIONSSERIALIZER_H
#define JXMPP_PUBSUBOPTIONSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOptions.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOptionsSerializer : public GenericPayloadSerializer<PubSubOptions> {
        public:
            PubSubOptionsSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOptionsSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOptions>) const override;
    };
}

#endif // JXMPP_PUBSUBOPTIONSSERIALIZER_H
