#include <JXMPP/Serializer/PayloadSerializers/PubSubEventItemSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubEventItemSerializer::PubSubEventItemSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubEventItemSerializer::~PubSubEventItemSerializer() {
}

std::string PubSubEventItemSerializer::serializePayload(std::shared_ptr<PubSubEventItem> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("item", "http://jabber.org/protocol/pubsub#event");
    if (payload->getNode()) {
        element.setAttribute("node", *payload->getNode());
    }
    if (payload->getPublisher()) {
        element.setAttribute("publisher", *payload->getPublisher());
    }
    for (const auto& item : payload->getData()) {
        element.addNode(std::make_shared<XMLRawTextNode>(serializers->getPayloadSerializer(item)->serialize(item)));
    }
    if (payload->getID()) {
        element.setAttribute("id", *payload->getID());
    }
    return element.serialize();
}
