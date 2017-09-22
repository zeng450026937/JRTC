#ifndef JXMPP_PUBSUBEVENTSUBSCRIPTIONSERIALIZER_H
#define JXMPP_PUBSUBEVENTSUBSCRIPTIONSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventSubscription.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventSubscriptionSerializer : public GenericPayloadSerializer<PubSubEventSubscription> {
        public:
            PubSubEventSubscriptionSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventSubscriptionSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventSubscription>) const override;

        private:
            static std::string serializeSubscriptionType(PubSubEventSubscription::SubscriptionType);
    };
}

#endif // JXMPP_PUBSUBEVENTSUBSCRIPTIONSERIALIZER_H
