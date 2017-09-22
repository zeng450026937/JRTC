#include <JXMPP/Serializer/PayloadSerializers/PubSubConfigureSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubConfigureSerializer::PubSubConfigureSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubConfigureSerializer::~PubSubConfigureSerializer() {
}

std::string PubSubConfigureSerializer::serializePayload(std::shared_ptr<PubSubConfigure> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("configure", "http://jabber.org/protocol/pubsub");
    element.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(payload->getData())));
    return element.serialize();
}
