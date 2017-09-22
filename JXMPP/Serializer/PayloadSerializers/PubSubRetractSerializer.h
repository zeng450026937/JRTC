#ifndef JXMPP_PUBSUBRETRACTSERIALIZER_H
#define JXMPP_PUBSUBRETRACTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubRetract.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubRetractSerializer : public GenericPayloadSerializer<PubSubRetract> {
        public:
            PubSubRetractSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubRetractSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubRetract>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBRETRACTSERIALIZER_H
