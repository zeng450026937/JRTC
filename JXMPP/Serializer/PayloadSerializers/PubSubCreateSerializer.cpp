#include <JXMPP/Serializer/PayloadSerializers/PubSubCreateSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubCreateSerializer::PubSubCreateSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubCreateSerializer::~PubSubCreateSerializer() {
}

std::string PubSubCreateSerializer::serializePayload(std::shared_ptr<PubSubCreate> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("create", "http://jabber.org/protocol/pubsub");
    element.setAttribute("node", payload->getNode());
    return element.serialize();
}
