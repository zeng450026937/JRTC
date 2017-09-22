#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerPurgeSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubOwnerPurgeSerializer::PubSubOwnerPurgeSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubOwnerPurgeSerializer::~PubSubOwnerPurgeSerializer() {
}

std::string PubSubOwnerPurgeSerializer::serializePayload(std::shared_ptr<PubSubOwnerPurge> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("purge", "http://jabber.org/protocol/pubsub#owner");
    element.setAttribute("node", payload->getNode());
    return element.serialize();
}
