#ifndef JXMPP_PUBSUBDEFAULTSERIALIZER_H
#define JXMPP_PUBSUBDEFAULTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubDefault.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubDefaultSerializer : public GenericPayloadSerializer<PubSubDefault> {
        public:
            PubSubDefaultSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubDefaultSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubDefault>) const override;

        private:
            static std::string serializeType(PubSubDefault::Type);
    };
}

#endif // JXMPP_PUBSUBDEFAULTSERIALIZER_H
