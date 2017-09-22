#ifndef JXMPP_USERTUNESERIALIZER_H
#define JXMPP_USERTUNESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/UserTune.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API UserTuneSerializer : public GenericPayloadSerializer<UserTune> {
        public:
            UserTuneSerializer(PayloadSerializerCollection* serializers);
            virtual ~UserTuneSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<UserTune>) const override;
    };
}

#endif // JXMPP_USERTUNESERIALIZER_H
