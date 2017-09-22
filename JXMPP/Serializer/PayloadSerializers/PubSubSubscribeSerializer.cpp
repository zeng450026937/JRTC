#include <JXMPP/Serializer/PayloadSerializers/PubSubSubscribeSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubSubscribeSerializer::PubSubSubscribeSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubSubscribeSerializer::~PubSubSubscribeSerializer() {
}

std::string PubSubSubscribeSerializer::serializePayload(std::shared_ptr<PubSubSubscribe> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("subscribe", "http://jabber.org/protocol/pubsub");
    if (payload->getNode()) {
        element.setAttribute("node", *payload->getNode());
    }
    element.setAttribute("jid", payload->getJID());
    return element.serialize();
}
