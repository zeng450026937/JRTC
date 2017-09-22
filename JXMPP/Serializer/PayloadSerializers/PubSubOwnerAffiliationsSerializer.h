#ifndef JXMPP_PUBSUBOWNERAFFILIATIONSSERIALIZER_H
#define JXMPP_PUBSUBOWNERAFFILIATIONSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerAffiliations.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerAffiliationsSerializer : public GenericPayloadSerializer<PubSubOwnerAffiliations> {
        public:
            PubSubOwnerAffiliationsSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerAffiliationsSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerAffiliations>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_PUBSUBOWNERAFFILIATIONSSERIALIZER_H
