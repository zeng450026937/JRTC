#ifndef JXMPP_PUBSUBOWNERDELETESERIALIZER_H
#define JXMPP_PUBSUBOWNERDELETESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerDelete.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerDeleteSerializer : public GenericPayloadSerializer<PubSubOwnerDelete> {
        public:
            PubSubOwnerDeleteSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerDeleteSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerDelete>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBOWNERDELETESERIALIZER_H
