#ifndef JXMPP_USERLOCATIONSERIALIZER_H
#define JXMPP_USERLOCATIONSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/UserLocation.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API UserLocationSerializer : public GenericPayloadSerializer<UserLocation> {
        public:
            UserLocationSerializer(PayloadSerializerCollection* serializers);
            virtual ~UserLocationSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<UserLocation>) const override;
    };
}

#endif // JXMPP_USERLOCATIONSERIALIZER_H
