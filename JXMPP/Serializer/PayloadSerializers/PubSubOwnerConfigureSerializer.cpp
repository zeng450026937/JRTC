#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerConfigureSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubOwnerConfigureSerializer::PubSubOwnerConfigureSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubOwnerConfigureSerializer::~PubSubOwnerConfigureSerializer() {
}

std::string PubSubOwnerConfigureSerializer::serializePayload(std::shared_ptr<PubSubOwnerConfigure> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("configure", "http://jabber.org/protocol/pubsub#owner");
    if (payload->getNode()) {
        element.setAttribute("node", *payload->getNode());
    }
    element.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(payload->getData())));
    return element.serialize();
}
