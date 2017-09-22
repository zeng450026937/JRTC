#ifndef JXMPP_PUBSUBSUBSCRIPTIONSSERIALIZER_H
#define JXMPP_PUBSUBSUBSCRIPTIONSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubSubscriptions.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubSubscriptionsSerializer : public GenericPayloadSerializer<PubSubSubscriptions> {
        public:
            PubSubSubscriptionsSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubSubscriptionsSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubSubscriptions>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIPTIONSSERIALIZER_H
