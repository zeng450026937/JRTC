#ifndef JXMPP_PUBSUBOWNERCONFIGURESERIALIZER_H
#define JXMPP_PUBSUBOWNERCONFIGURESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerConfigure.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerConfigureSerializer : public GenericPayloadSerializer<PubSubOwnerConfigure> {
        public:
            PubSubOwnerConfigureSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerConfigureSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerConfigure>) const override;
    };
}

#endif // JXMPP_PUBSUBOWNERCONFIGURESERIALIZER_H
