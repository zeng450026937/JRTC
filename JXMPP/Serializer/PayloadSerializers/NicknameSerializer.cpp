#include <JXMPP/Serializer/PayloadSerializers/NicknameSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

NicknameSerializer::NicknameSerializer() : GenericPayloadSerializer<Nickname>() {
}

std::string NicknameSerializer::serializePayload(std::shared_ptr<Nickname> nick)  const {
    XMLElement nickElement("nick", "http://jabber.org/protocol/nick");
    nickElement.addNode(std::make_shared<XMLTextNode>(nick->getNickname()));
    return nickElement.serialize();
}

}
