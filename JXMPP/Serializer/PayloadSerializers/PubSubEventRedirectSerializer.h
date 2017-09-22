#ifndef JXMPP_PUBSUBEVENTREDIRECTSERIALIZER_H
#define JXMPP_PUBSUBEVENTREDIRECTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventRedirect.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventRedirectSerializer : public GenericPayloadSerializer<PubSubEventRedirect> {
        public:
            PubSubEventRedirectSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventRedirectSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventRedirect>) const override;
    };
}

#endif // JXMPP_PUBSUBEVENTREDIRECTSERIALIZER_H
