#ifndef JXMPP_PUBSUBEVENTPURGESERIALIZER_H
#define JXMPP_PUBSUBEVENTPURGESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventPurge.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventPurgeSerializer : public GenericPayloadSerializer<PubSubEventPurge> {
        public:
            PubSubEventPurgeSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventPurgeSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventPurge>) const override;
    };
}

#endif // JXMPP_PUBSUBEVENTPURGESERIALIZER_H
