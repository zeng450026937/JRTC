#ifndef JXMPP_PUBSUBEVENTSERIALIZER_H
#define JXMPP_PUBSUBEVENTSERIALIZER_H

#include <memory>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEvent.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventSerializer : public GenericPayloadSerializer<PubSubEvent> {
        public:
            PubSubEventSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEvent>) const override;

        private:
            std::vector< std::shared_ptr<PayloadSerializer> > pubsubSerializers;
    };
}

#endif // JXMPP_PUBSUBEVENTSERIALIZER_H
