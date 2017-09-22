#include <JXMPP/Serializer/PayloadSerializers/PrivateStorageSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

PrivateStorageSerializer::PrivateStorageSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

std::string PrivateStorageSerializer::serializePayload(std::shared_ptr<PrivateStorage> storage)    const {
    XMLElement storageElement("query", "jabber:iq:private");
    std::shared_ptr<Payload> payload = storage->getPayload();
    if (payload) {
        PayloadSerializer* serializer = serializers->getPayloadSerializer(payload);
        if (serializer) {
            storageElement.addNode(std::make_shared<XMLRawTextNode>(serializer->serialize(payload)));
        }
    }
    return storageElement.serialize();
}

}
