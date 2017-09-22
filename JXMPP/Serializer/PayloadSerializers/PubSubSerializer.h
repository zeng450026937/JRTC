#ifndef JXMPP_PUBSUBSERIALIZER_H
#define JXMPP_PUBSUBSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSub.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubSerializer : public GenericPayloadSerializer<PubSub> {
        public:
            PubSubSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSub>) const override;

        private:
            std::vector< std::shared_ptr<PayloadSerializer> > pubsubSerializers;
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBSERIALIZER_H
