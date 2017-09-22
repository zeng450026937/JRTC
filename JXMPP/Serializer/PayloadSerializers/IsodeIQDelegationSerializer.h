#ifndef JXMPP_ISODEIQDELEGATIONSERIALIZER_H
#define JXMPP_ISODEIQDELEGATIONSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IsodeIQDelegation.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API IsodeIQDelegationSerializer : public GenericPayloadSerializer<IsodeIQDelegation> {
        public:
            IsodeIQDelegationSerializer(PayloadSerializerCollection* serializers);
            virtual ~IsodeIQDelegationSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<IsodeIQDelegation>) const override;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_ISODEIQDELEGATIONSERIALIZER_H
