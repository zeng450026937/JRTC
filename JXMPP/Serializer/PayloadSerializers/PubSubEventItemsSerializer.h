#ifndef JXMPP_PUBSUBEVENTITEMSSERIALIZER_H
#define JXMPP_PUBSUBEVENTITEMSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventItems.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventItemsSerializer : public GenericPayloadSerializer<PubSubEventItems> {
        public:
            PubSubEventItemsSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventItemsSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventItems>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBEVENTITEMSSERIALIZER_H
