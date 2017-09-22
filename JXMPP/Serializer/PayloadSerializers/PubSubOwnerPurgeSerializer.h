#ifndef JXMPP_PUBSUBOWNERPURGESERIALIZER_H
#define JXMPP_PUBSUBOWNERPURGESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerPurge.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerPurgeSerializer : public GenericPayloadSerializer<PubSubOwnerPurge> {
        public:
            PubSubOwnerPurgeSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerPurgeSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerPurge>) const override;
    };
}

#endif // JXMPP_PUBSUBOWNERPURGESERIALIZER_H
