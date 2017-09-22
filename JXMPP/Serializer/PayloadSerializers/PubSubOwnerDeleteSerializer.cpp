#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerDeleteSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerRedirectSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubOwnerDeleteSerializer::PubSubOwnerDeleteSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubOwnerDeleteSerializer::~PubSubOwnerDeleteSerializer() {
}

std::string PubSubOwnerDeleteSerializer::serializePayload(std::shared_ptr<PubSubOwnerDelete> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("delete", "http://jabber.org/protocol/pubsub#owner");
    element.setAttribute("node", payload->getNode());
    element.addNode(std::make_shared<XMLRawTextNode>(PubSubOwnerRedirectSerializer(serializers).serialize(payload->getRedirect())));
    return element.serialize();
}
