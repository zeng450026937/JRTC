#include <JXMPP/Serializer/PayloadSerializers/PubSubEventConfigurationSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubEventConfigurationSerializer::PubSubEventConfigurationSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubEventConfigurationSerializer::~PubSubEventConfigurationSerializer() {
}

std::string PubSubEventConfigurationSerializer::serializePayload(std::shared_ptr<PubSubEventConfiguration> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("configuration", "http://jabber.org/protocol/pubsub#event");
    element.setAttribute("node", payload->getNode());
    element.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(payload->getData())));
    return element.serialize();
}
