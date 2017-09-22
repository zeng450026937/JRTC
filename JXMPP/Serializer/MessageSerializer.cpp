#include <JXMPP/Serializer/MessageSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {

MessageSerializer::MessageSerializer(PayloadSerializerCollection* payloadSerializers, const boost::optional<std::string>& explicitNS) :
        GenericStanzaSerializer<Message>("message", payloadSerializers, explicitNS) {
}

void MessageSerializer::setStanzaSpecificAttributesGeneric(
        std::shared_ptr<Message> message,
        XMLElement& element) const {
    if (message->getType() == Message::Chat) {
        element.setAttribute("type", "chat");
    }
    else if (message->getType() == Message::Groupchat) {
        element.setAttribute("type", "groupchat");
    }
    else if (message->getType() == Message::Headline) {
        element.setAttribute("type", "headline");
    }
    else if (message->getType() == Message::Error) {
        element.setAttribute("type", "error");
    }
}

}
