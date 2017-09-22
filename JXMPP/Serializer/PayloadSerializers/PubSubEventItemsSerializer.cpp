#include <JXMPP/Serializer/PayloadSerializers/PubSubEventItemsSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventItemSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventRetractSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubEventItemsSerializer::PubSubEventItemsSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubEventItemsSerializer::~PubSubEventItemsSerializer() {
}

std::string PubSubEventItemsSerializer::serializePayload(std::shared_ptr<PubSubEventItems> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("items", "http://jabber.org/protocol/pubsub#event");
    element.setAttribute("node", payload->getNode());
    for (const auto& item : payload->getItems()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubEventItemSerializer(serializers).serialize(item)));
    }
    for (const auto& item : payload->getRetracts()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubEventRetractSerializer(serializers).serialize(item)));
    }
    return element.serialize();
}
