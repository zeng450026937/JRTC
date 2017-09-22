#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerRedirectSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubOwnerRedirectSerializer::PubSubOwnerRedirectSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubOwnerRedirectSerializer::~PubSubOwnerRedirectSerializer() {
}

std::string PubSubOwnerRedirectSerializer::serializePayload(std::shared_ptr<PubSubOwnerRedirect> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("redirect", "http://jabber.org/protocol/pubsub#owner");
    element.setAttribute("uri", payload->getURI());
    return element.serialize();
}
