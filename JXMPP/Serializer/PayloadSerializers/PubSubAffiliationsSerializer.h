#ifndef JXMPP_PUBSUBAFFILIATIONSSERIALIZER_H
#define JXMPP_PUBSUBAFFILIATIONSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubAffiliations.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubAffiliationsSerializer : public GenericPayloadSerializer<PubSubAffiliations> {
        public:
            PubSubAffiliationsSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubAffiliationsSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubAffiliations>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBAFFILIATIONSSERIALIZER_H
