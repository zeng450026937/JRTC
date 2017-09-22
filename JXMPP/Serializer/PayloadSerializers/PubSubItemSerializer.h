#ifndef JXMPP_PUBSUBITEMSERIALIZER_H
#define JXMPP_PUBSUBITEMSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubItem.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubItemSerializer : public GenericPayloadSerializer<PubSubItem> {
        public:
            PubSubItemSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubItemSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubItem>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBITEMSERIALIZER_H
