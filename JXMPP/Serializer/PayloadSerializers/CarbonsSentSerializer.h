#ifndef JXMPP_CARBONSSENTSERIALIZER_H
#define JXMPP_CARBONSSENTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsSent.h>
#include <JXMPP/Elements/Forwarded.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/ForwardedSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

namespace JXMPP {
    class JXMPP_API CarbonsSentSerializer : public GenericPayloadSerializer<CarbonsSent> {
        public:
            CarbonsSentSerializer(PayloadSerializerCollection* serializers);
            virtual ~CarbonsSentSerializer();

            virtual std::string serializePayload(std::shared_ptr<CarbonsSent> sent) const;

        private:
            PayloadSerializerCollection* serializers_;
    };
}

#endif // JXMPP_CARBONSSENTSERIALIZER_H
