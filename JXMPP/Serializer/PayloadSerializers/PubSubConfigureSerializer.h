#ifndef JXMPP_PUBSUBCONFIGURESERIALIZER_H
#define JXMPP_PUBSUBCONFIGURESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubConfigure.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubConfigureSerializer : public GenericPayloadSerializer<PubSubConfigure> {
        public:
            PubSubConfigureSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubConfigureSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubConfigure>) const override;
    };
}

#endif // JXMPP_PUBSUBCONFIGURESERIALIZER_H
