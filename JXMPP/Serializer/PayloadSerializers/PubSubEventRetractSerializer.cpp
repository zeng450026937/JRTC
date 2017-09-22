#include <JXMPP/Serializer/PayloadSerializers/PubSubEventRetractSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubEventRetractSerializer::PubSubEventRetractSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubEventRetractSerializer::~PubSubEventRetractSerializer() {
}

std::string PubSubEventRetractSerializer::serializePayload(std::shared_ptr<PubSubEventRetract> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("retract", "http://jabber.org/protocol/pubsub#event");
    element.setAttribute("id", payload->getID());
    return element.serialize();
}
