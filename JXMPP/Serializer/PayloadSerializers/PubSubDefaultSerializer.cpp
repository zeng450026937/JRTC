#include <JXMPP/Serializer/PayloadSerializers/PubSubDefaultSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubDefaultSerializer::PubSubDefaultSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubDefaultSerializer::~PubSubDefaultSerializer() {
}

std::string PubSubDefaultSerializer::serializePayload(std::shared_ptr<PubSubDefault> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("default", "http://jabber.org/protocol/pubsub");
    if (payload->getNode()) {
        element.setAttribute("node", *payload->getNode());
    }
    element.setAttribute("type", serializeType(payload->getType()));
    return element.serialize();
}

std::string PubSubDefaultSerializer::serializeType(PubSubDefault::Type value) {
    switch (value) {
        case PubSubDefault::None: return "none";
        case PubSubDefault::Collection: return "collection";
        case PubSubDefault::Leaf: return "leaf";
    }
    assert(false);
    return "";
}
