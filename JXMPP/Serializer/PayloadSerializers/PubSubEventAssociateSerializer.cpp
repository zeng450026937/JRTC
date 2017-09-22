#include <JXMPP/Serializer/PayloadSerializers/PubSubEventAssociateSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubEventAssociateSerializer::PubSubEventAssociateSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubEventAssociateSerializer::~PubSubEventAssociateSerializer() {
}

std::string PubSubEventAssociateSerializer::serializePayload(std::shared_ptr<PubSubEventAssociate> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("associate", "http://jabber.org/protocol/pubsub#event");
    element.setAttribute("node", payload->getNode());
    return element.serialize();
}
