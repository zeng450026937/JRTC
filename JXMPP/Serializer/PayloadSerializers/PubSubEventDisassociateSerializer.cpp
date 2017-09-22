#include <JXMPP/Serializer/PayloadSerializers/PubSubEventDisassociateSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubEventDisassociateSerializer::PubSubEventDisassociateSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubEventDisassociateSerializer::~PubSubEventDisassociateSerializer() {
}

std::string PubSubEventDisassociateSerializer::serializePayload(std::shared_ptr<PubSubEventDisassociate> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("disassociate", "http://jabber.org/protocol/pubsub#event");
    element.setAttribute("node", payload->getNode());
    return element.serialize();
}
