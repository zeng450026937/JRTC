#include <JXMPP/Serializer/PayloadSerializers/PubSubPublishSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubItemSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubPublishSerializer::PubSubPublishSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubPublishSerializer::~PubSubPublishSerializer() {
}

std::string PubSubPublishSerializer::serializePayload(std::shared_ptr<PubSubPublish> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("publish", "http://jabber.org/protocol/pubsub");
    element.setAttribute("node", payload->getNode());
    for (const auto& item : payload->getItems()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubItemSerializer(serializers).serialize(item)));
    }
    return element.serialize();
}
