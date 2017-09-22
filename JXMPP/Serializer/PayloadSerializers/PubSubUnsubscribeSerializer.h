#ifndef JXMPP_PUBSUBUNSUBSCRIBESERIALIZER_H
#define JXMPP_PUBSUBUNSUBSCRIBESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubUnsubscribe.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubUnsubscribeSerializer : public GenericPayloadSerializer<PubSubUnsubscribe> {
        public:
            PubSubUnsubscribeSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubUnsubscribeSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubUnsubscribe>) const override;
    };
}

#endif // JXMPP_PUBSUBUNSUBSCRIBESERIALIZER_H
