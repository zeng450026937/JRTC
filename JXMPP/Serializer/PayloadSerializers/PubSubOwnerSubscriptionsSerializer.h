#ifndef JXMPP_PUBSUBOWNERSUBSCRIPTIONSSERIALIZER_H
#define JXMPP_PUBSUBOWNERSUBSCRIPTIONSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerSubscriptions.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerSubscriptionsSerializer : public GenericPayloadSerializer<PubSubOwnerSubscriptions> {
        public:
            PubSubOwnerSubscriptionsSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerSubscriptionsSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerSubscriptions>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBOWNERSUBSCRIPTIONSSERIALIZER_H
