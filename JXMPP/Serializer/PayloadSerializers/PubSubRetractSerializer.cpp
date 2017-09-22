#include <JXMPP/Serializer/PayloadSerializers/PubSubRetractSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubItemSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubRetractSerializer::PubSubRetractSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubRetractSerializer::~PubSubRetractSerializer() {
}

std::string PubSubRetractSerializer::serializePayload(std::shared_ptr<PubSubRetract> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("retract", "http://jabber.org/protocol/pubsub");
    element.setAttribute("node", payload->getNode());
    for (const auto& item : payload->getItems()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubItemSerializer(serializers).serialize(item)));
    }
    if (payload->isNotify().is_initialized()) {
        element.setAttribute("notify", payload->isNotify().get() ? "true" : "false");
    }
    return element.serialize();
}
