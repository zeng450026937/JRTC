#ifndef JXMPP_PUBSUBOWNERAFFILIATIONSERIALIZER_H
#define JXMPP_PUBSUBOWNERAFFILIATIONSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerAffiliation.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerAffiliationSerializer : public GenericPayloadSerializer<PubSubOwnerAffiliation> {
        public:
            PubSubOwnerAffiliationSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerAffiliationSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerAffiliation>) const override;

        private:
            static std::string serializeType(PubSubOwnerAffiliation::Type);
    };
}

#endif // JXMPP_PUBSUBOWNERAFFILIATIONSERIALIZER_H
