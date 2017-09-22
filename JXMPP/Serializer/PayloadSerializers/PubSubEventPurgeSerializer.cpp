#include <JXMPP/Serializer/PayloadSerializers/PubSubEventPurgeSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubEventPurgeSerializer::PubSubEventPurgeSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubEventPurgeSerializer::~PubSubEventPurgeSerializer() {
}

std::string PubSubEventPurgeSerializer::serializePayload(std::shared_ptr<PubSubEventPurge> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("purge", "http://jabber.org/protocol/pubsub#event");
    element.setAttribute("node", payload->getNode());
    return element.serialize();
}
