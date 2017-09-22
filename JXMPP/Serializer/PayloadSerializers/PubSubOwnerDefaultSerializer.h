#ifndef JXMPP_PUBSUBOWNERDEFAULTSERIALIZER_H
#define JXMPP_PUBSUBOWNERDEFAULTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerDefault.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerDefaultSerializer : public GenericPayloadSerializer<PubSubOwnerDefault> {
        public:
            PubSubOwnerDefaultSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerDefaultSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerDefault>) const override;
    };
}

#endif // JXMPP_PUBSUBOWNERDEFAULTSERIALIZER_H
