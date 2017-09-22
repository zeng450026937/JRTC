#ifndef JXMPP_PUBSUBEVENTCONFIGURATIONSERIALIZER_H
#define JXMPP_PUBSUBEVENTCONFIGURATIONSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventConfiguration.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventConfigurationSerializer : public GenericPayloadSerializer<PubSubEventConfiguration> {
        public:
            PubSubEventConfigurationSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventConfigurationSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventConfiguration>) const override;
    };
}

#endif // JXMPP_PUBSUBEVENTCONFIGURATIONSERIALIZER_H
