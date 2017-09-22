#ifndef JXMPP_PUBSUBSUBSCRIPTIONSERIALIZER_H
#define JXMPP_PUBSUBSUBSCRIPTIONSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubSubscription.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubSubscriptionSerializer : public GenericPayloadSerializer<PubSubSubscription> {
        public:
            PubSubSubscriptionSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubSubscriptionSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubSubscription>) const override;

        private:
            static std::string serializeSubscriptionType(PubSubSubscription::SubscriptionType);

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIPTIONSERIALIZER_H
