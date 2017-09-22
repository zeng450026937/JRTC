#include <JXMPP/Serializer/PayloadSerializers/ForwardedSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Elements/Delay.h>
#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/Serializer/GenericStanzaSerializer.h>
#include <JXMPP/Serializer/IQSerializer.h>
#include <JXMPP/Serializer/MessageSerializer.h>
#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/DelaySerializer.h>
#include <JXMPP/Serializer/PresenceSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

ForwardedSerializer::ForwardedSerializer(PayloadSerializerCollection* serializers) : serializers_(serializers) {
}

ForwardedSerializer::~ForwardedSerializer() {
}

std::string ForwardedSerializer::serializePayload(std::shared_ptr<Forwarded> payload) const {
    if (!payload) {
        return "";
    }

    XMLElement element("forwarded", "urn:xmpp:forward:0");

    if (payload->getDelay()) {
        element.addNode(std::make_shared<XMLRawTextNode>(DelaySerializer().serialize(payload->getDelay())));
    }

    if (payload->getStanza()) { /* find out what type of stanza we are dealing with and branch into the correct serializer*/
        std::shared_ptr<IQ> iq;
        std::shared_ptr<Message> message;
        std::shared_ptr<Presence> presence;
        const std::string ns = "jabber:client";
        if ((iq = std::dynamic_pointer_cast<IQ>(payload->getStanza()))) {
            element.addNode(std::make_shared<XMLRawTextNode>(safeByteArrayToString(IQSerializer(serializers_).serialize(iq, ns))));
        } else if ((message = std::dynamic_pointer_cast<Message>(payload->getStanza()))) {
            element.addNode(std::make_shared<XMLRawTextNode>(safeByteArrayToString(MessageSerializer(serializers_).serialize(message, ns))));
        } else if ((presence = std::dynamic_pointer_cast<Presence>(payload->getStanza()))) {
            element.addNode(std::make_shared<XMLRawTextNode>(safeByteArrayToString(PresenceSerializer(serializers_).serialize(presence, ns))));
        }
    }

    return element.serialize();
}
