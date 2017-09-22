#ifndef JXMPP_PUBSUBEVENTASSOCIATESERIALIZER_H
#define JXMPP_PUBSUBEVENTASSOCIATESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventAssociate.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class PayloadSerializerCollection;

    class JXMPP_API PubSubEventAssociateSerializer : public GenericPayloadSerializer<PubSubEventAssociate> {
        public:
            PubSubEventAssociateSerializer(PayloadSerializerCollection* serializers);
            virtual ~PubSubEventAssociateSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<PubSubEventAssociate>) const override;
    };
}

#endif // JXMPP_PUBSUBEVENTASSOCIATESERIALIZER_H
