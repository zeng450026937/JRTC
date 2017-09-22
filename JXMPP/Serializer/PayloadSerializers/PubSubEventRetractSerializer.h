#ifndef JXMPP_PUBSUBEVENTRETRACTSERIALIZER_H
#define JXMPP_PUBSUBEVENTRETRACTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventRetract.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventRetractSerializer : public GenericPayloadSerializer<PubSubEventRetract> {
        public:
            PubSubEventRetractSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventRetractSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventRetract>) const override;
    };
}

#endif // JXMPP_PUBSUBEVENTRETRACTSERIALIZER_H
