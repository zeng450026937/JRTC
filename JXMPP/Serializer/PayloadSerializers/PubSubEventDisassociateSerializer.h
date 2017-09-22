#ifndef JXMPP_PUBSUBEVENTDISASSOCIATESERIALIZER_H
#define JXMPP_PUBSUBEVENTDISASSOCIATESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventDisassociate.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventDisassociateSerializer : public GenericPayloadSerializer<PubSubEventDisassociate> {
        public:
            PubSubEventDisassociateSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventDisassociateSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventDisassociate>) const override;
    };
}

#endif // JXMPP_PUBSUBEVENTDISASSOCIATESERIALIZER_H
