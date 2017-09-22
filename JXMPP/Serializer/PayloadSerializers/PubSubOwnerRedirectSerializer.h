#ifndef JXMPP_PUBSUBOWNERREDIRECTSERIALIZER_H
#define JXMPP_PUBSUBOWNERREDIRECTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerRedirect.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubOwnerRedirectSerializer : public GenericPayloadSerializer<PubSubOwnerRedirect> {
        public:
            PubSubOwnerRedirectSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubOwnerRedirectSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubOwnerRedirect>) const override;
    };
}

#endif // JXMPP_PUBSUBOWNERREDIRECTSERIALIZER_H
