#ifndef JXMPP_CARBONSRECEIVEDSERIALIZER_H
#define JXMPP_CARBONSRECEIVEDSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsReceived.h>
#include <JXMPP/Elements/Forwarded.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ForwardedSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

namespace JXMPP {
    class JXMPP_API CarbonsReceivedSerializer : public GenericPayloadSerializer<CarbonsReceived> {
        public:
            CarbonsReceivedSerializer(PayloadSerializerCollection* serializers);
            virtual ~CarbonsReceivedSerializer();

            virtual std::string serializePayload(std::shared_ptr<CarbonsReceived> received) const;

        private:
            PayloadSerializerCollection* serializers_;
    };
}

#endif // JXMPP_CARBONSRECEIVEDSERIALIZER_H
