#ifndef JXMPP_PUBSUBEVENTDELETESERIALIZER_H
#define JXMPP_PUBSUBEVENTDELETESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventDelete.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventDeleteSerializer : public GenericPayloadSerializer<PubSubEventDelete> {
        public:
            PubSubEventDeleteSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventDeleteSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventDelete>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBEVENTDELETESERIALIZER_H
