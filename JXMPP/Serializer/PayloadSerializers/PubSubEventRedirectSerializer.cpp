#include <JXMPP/Serializer/PayloadSerializers/PubSubEventRedirectSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubEventRedirectSerializer::PubSubEventRedirectSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubEventRedirectSerializer::~PubSubEventRedirectSerializer() {
}

std::string PubSubEventRedirectSerializer::serializePayload(std::shared_ptr<PubSubEventRedirect> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("redirect", "http://jabber.org/protocol/pubsub#event");
    element.setAttribute("uri", payload->getURI());
    return element.serialize();
}
