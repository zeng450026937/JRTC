#include <JXMPP/Serializer/PayloadSerializers/PubSubOptionsSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubOptionsSerializer::PubSubOptionsSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubOptionsSerializer::~PubSubOptionsSerializer() {
}

std::string PubSubOptionsSerializer::serializePayload(std::shared_ptr<PubSubOptions> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("options", "http://jabber.org/protocol/pubsub");
    element.setAttribute("node", payload->getNode());
    element.setAttribute("jid", payload->getJID());
    element.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(payload->getData())));
    if (payload->getSubscriptionID()) {
        element.setAttribute("subid", *payload->getSubscriptionID());
    }
    return element.serialize();
}
