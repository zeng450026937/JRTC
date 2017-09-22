#ifndef JXMPP_PUBSUBERRORSERIALIZER_H
#define JXMPP_PUBSUBERRORSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubError.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API PubSubErrorSerializer : public GenericPayloadSerializer<PubSubError> {
        public:
            PubSubErrorSerializer();
            virtual ~PubSubErrorSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubError>) const override;

        private:
            static std::string serializeType(PubSubError::Type);
            static std::string serializeUnsupportedFeatureType(PubSubError::UnsupportedFeatureType);
    };
}

#endif // JXMPP_PUBSUBERRORSERIALIZER_H
