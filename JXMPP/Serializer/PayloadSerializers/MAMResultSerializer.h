#ifndef JXMPP_MAMRESULTSERIALIZER_H
#define JXMPP_MAMRESULTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MAMResult.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API MAMResultSerializer : public GenericPayloadSerializer<MAMResult> {
        public:
            MAMResultSerializer(PayloadSerializerCollection* serializers);
            virtual ~MAMResultSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<MAMResult>) const override;

        private:
            PayloadSerializerCollection* serializers_;
    };
}

#endif // JXMPP_MAMRESULTSERIALIZER_H
