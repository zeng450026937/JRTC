#include <JXMPP/Serializer/PayloadSerializers/PubSubSubscribeOptionsSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubSubscribeOptionsSerializer::PubSubSubscribeOptionsSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubSubscribeOptionsSerializer::~PubSubSubscribeOptionsSerializer() {
}

std::string PubSubSubscribeOptionsSerializer::serializePayload(std::shared_ptr<PubSubSubscribeOptions> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("subscribe-options", "http://jabber.org/protocol/pubsub");
    element.addNode(payload->isRequired() ? std::make_shared<XMLElement>("required", "") : std::shared_ptr<XMLElement>());
    return element.serialize();
}
