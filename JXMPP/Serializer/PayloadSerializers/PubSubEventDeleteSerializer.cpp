#include <JXMPP/Serializer/PayloadSerializers/PubSubEventDeleteSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventRedirectSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubEventDeleteSerializer::PubSubEventDeleteSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubEventDeleteSerializer::~PubSubEventDeleteSerializer() {
}

std::string PubSubEventDeleteSerializer::serializePayload(std::shared_ptr<PubSubEventDelete> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("delete", "http://jabber.org/protocol/pubsub#event");
    element.setAttribute("node", payload->getNode());
    element.addNode(std::make_shared<XMLRawTextNode>(PubSubEventRedirectSerializer(serializers).serialize(payload->getRedirects())));
    return element.serialize();
}
