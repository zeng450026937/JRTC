/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Serializer/PayloadSerializers/MIXRegisterNickSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

MIXRegisterNickSerializer::MIXRegisterNickSerializer() : GenericPayloadSerializer<MIXRegisterNick>() {
}

std::string MIXRegisterNickSerializer::serializePayload(std::shared_ptr<MIXRegisterNick> payload)  const {
    XMLElement registernickElement("register", "urn:xmpp:mix:0");

    auto nickElement = std::make_shared<XMLElement>("nick");
    nickElement->addNode(std::make_shared<XMLTextNode>(payload->getNick()));
    registernickElement.addNode(nickElement);

    return registernickElement.serialize();
}

}
