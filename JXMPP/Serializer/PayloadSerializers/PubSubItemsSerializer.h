#ifndef JXMPP_PUBSUBITEMSSERIALIZER_H
#define JXMPP_PUBSUBITEMSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubItems.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubItemsSerializer : public GenericPayloadSerializer<PubSubItems> {
        public:
            PubSubItemsSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubItemsSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubItems>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBITEMSSERIALIZER_H
