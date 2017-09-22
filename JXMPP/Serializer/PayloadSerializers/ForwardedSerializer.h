#ifndef JXMPP_FORWARDEDSERIALIZER_H
#define JXMPP_FORWARDEDSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Forwarded.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API ForwardedSerializer : public GenericPayloadSerializer<Forwarded> {
        public:
            ForwardedSerializer(PayloadSerializerCollection* serializers);
            virtual ~ForwardedSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<Forwarded>) const override;

        private:
            PayloadSerializerCollection* serializers_;
    };
}

#endif // JXMPP_FORWARDEDSERIALIZER_H
