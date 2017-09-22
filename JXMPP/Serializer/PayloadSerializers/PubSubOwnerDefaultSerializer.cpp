#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerDefaultSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubOwnerDefaultSerializer::PubSubOwnerDefaultSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubOwnerDefaultSerializer::~PubSubOwnerDefaultSerializer() {
}

std::string PubSubOwnerDefaultSerializer::serializePayload(std::shared_ptr<PubSubOwnerDefault> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("default", "http://jabber.org/protocol/pubsub#owner");
    element.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(payload->getData())));
    return element.serialize();
}
