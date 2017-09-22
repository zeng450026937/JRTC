#ifndef JXMPP_PUBSUBPUBLISHSERIALIZER_H
#define JXMPP_PUBSUBPUBLISHSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubPublish.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubPublishSerializer : public GenericPayloadSerializer<PubSubPublish> {
        public:
            PubSubPublishSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubPublishSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubPublish>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBPUBLISHSERIALIZER_H
