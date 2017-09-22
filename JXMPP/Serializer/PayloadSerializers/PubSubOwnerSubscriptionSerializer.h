#ifndef JXMPP_PUBSUBOWNERSUBSCRIPTIONSERIALIZER_H
#define JXMPP_PUBSUBOWNERSUBSCRIPTIONSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerSubscription.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerSubscriptionSerializer : public GenericPayloadSerializer<PubSubOwnerSubscription> {
        public:
            PubSubOwnerSubscriptionSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerSubscriptionSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerSubscription>) const override;

        private:
            static std::string serializeSubscriptionType(PubSubOwnerSubscription::SubscriptionType);
    };
}

#endif // JXMPP_PUBSUBOWNERSUBSCRIPTIONSERIALIZER_H
