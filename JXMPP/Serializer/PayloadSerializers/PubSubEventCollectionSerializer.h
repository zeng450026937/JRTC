#ifndef JXMPP_PUBSUBEVENTCOLLECTIONSERIALIZER_H
#define JXMPP_PUBSUBEVENTCOLLECTIONSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventCollection.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventCollectionSerializer : public GenericPayloadSerializer<PubSubEventCollection> {
        public:
            PubSubEventCollectionSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventCollectionSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventCollection>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBEVENTCOLLECTIONSERIALIZER_H
