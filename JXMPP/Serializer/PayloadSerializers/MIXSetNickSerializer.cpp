/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Serializer/PayloadSerializers/MIXSetNickSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

MIXSetNickSerializer::MIXSetNickSerializer() : GenericPayloadSerializer<MIXSetNick>() {
}

std::string MIXSetNickSerializer::serializePayload(std::shared_ptr<MIXSetNick> payload)  const {
    XMLElement setnickElement("setnick", "urn:xmpp:mix:0");

    auto nickElement = std::make_shared<XMLElement>("nick");
    nickElement->addNode(std::make_shared<XMLTextNode>(payload->getNick()));
    setnickElement.addNode(nickElement);

    return setnickElement.serialize();
}

}
