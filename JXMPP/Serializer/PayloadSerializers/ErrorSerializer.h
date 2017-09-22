#ifndef JXMPP_ERRORSERIALIZER_H
#define JXMPP_ERRORSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API ErrorSerializer : public GenericPayloadSerializer<ErrorPayload> {
        public:
            ErrorSerializer(PayloadSerializerCollection* serializers);

            virtual std::string serializePayload(std::shared_ptr<ErrorPayload> error)  const;

        private:
            PayloadSerializerCollection* serializers;
    };
}

#endif // JXMPP_ERRORSERIALIZER_H
