#ifndef JXMPP_PUBSUBEVENTITEMSERIALIZER_H
#define JXMPP_PUBSUBEVENTITEMSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventItem.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventItemSerializer : public GenericPayloadSerializer<PubSubEventItem> {
        public:
            PubSubEventItemSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventItemSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventItem>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBEVENTITEMSERIALIZER_H
