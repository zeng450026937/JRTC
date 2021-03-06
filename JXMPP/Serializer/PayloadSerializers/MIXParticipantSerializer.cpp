/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Serializer/PayloadSerializers/MIXParticipantSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

MIXParticipantSerializer::MIXParticipantSerializer() : GenericPayloadSerializer<MIXParticipant>() {
}

std::string MIXParticipantSerializer::serializePayload(std::shared_ptr<MIXParticipant> payload)  const {
    XMLElement participantElement("participant", "urn:xmpp:mix:0");

    if (payload->getNick()) {
        std::shared_ptr<XMLElement> nickElement = std::make_shared<XMLElement>("nick");
        nickElement->addNode(std::make_shared<XMLTextNode>(*payload->getNick()));
        participantElement.addNode(nickElement);
    }

    if (payload->getJID()) {
        std::shared_ptr<XMLElement> jidElement = std::make_shared<XMLElement>("jid");
        jidElement->addNode(std::make_shared<XMLTextNode>(*payload->getJID()));
        participantElement.addNode(jidElement);
    }
    return participantElement.serialize();
}

}
