#ifndef JXMPP_PUBSUBAFFILIATIONSERIALIZER_H
#define JXMPP_PUBSUBAFFILIATIONSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubAffiliation.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubAffiliationSerializer : public GenericPayloadSerializer<PubSubAffiliation> {
        public:
            PubSubAffiliationSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubAffiliationSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubAffiliation>) const override;

        private:
            static std::string serializeType(PubSubAffiliation::Type);
    };
}

#endif // JXMPP_PUBSUBAFFILIATIONSERIALIZER_H
