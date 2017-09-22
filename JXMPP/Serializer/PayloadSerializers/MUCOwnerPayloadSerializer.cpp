#include <JXMPP/Serializer/PayloadSerializers/MUCOwnerPayloadSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

namespace JXMPP {

MUCOwnerPayloadSerializer::MUCOwnerPayloadSerializer(PayloadSerializerCollection* serializers) : GenericPayloadSerializer<MUCOwnerPayload>(), serializers(serializers) {
}

std::string MUCOwnerPayloadSerializer::serializePayload(std::shared_ptr<MUCOwnerPayload> mucOwner)  const {
    XMLElement mucElement("query", "http://jabber.org/protocol/muc#owner");
    std::shared_ptr<Payload> payload = mucOwner->getPayload();
    if (payload) {
        PayloadSerializer* serializer = serializers->getPayloadSerializer(payload);
        if (serializer) {
            mucElement.addNode(std::make_shared<XMLRawTextNode>(serializer->serialize(payload)));
        }
    }
    return mucElement.serialize();
}

}
