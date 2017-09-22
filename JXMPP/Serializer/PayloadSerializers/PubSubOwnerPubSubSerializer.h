#ifndef JXMPP_PUBSUBOWNERPUBSUBSERIALIZER_H
#define JXMPP_PUBSUBOWNERPUBSUBSERIALIZER_H

#include <memory>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerPubSub.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerPubSubSerializer : public GenericPayloadSerializer<PubSubOwnerPubSub> {
        public:
            PubSubOwnerPubSubSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerPubSubSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerPubSub>) const override;

        private:
            std::vector< std::shared_ptr<PayloadSerializer> > pubsubSerializers;
    };
}

#endif // JXMPP_PUBSUBOWNERPUBSUBSERIALIZER_H
