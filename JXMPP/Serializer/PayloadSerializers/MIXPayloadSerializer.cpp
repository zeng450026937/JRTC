/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Serializer/PayloadSerializers/MIXPayloadSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

MIXPayloadSerializer::MIXPayloadSerializer() : GenericPayloadSerializer<MIXPayload>() {
}

std::string MIXPayloadSerializer::serializePayload(std::shared_ptr<MIXPayload> payload)  const {
    XMLElement mixElement("mix", "urn:xmpp:mix:0");

    if (payload->getNick()) {
        std::shared_ptr<XMLElement> nickElement = std::make_shared<XMLElement>("nick");
        nickElement->addNode(std::make_shared<XMLTextNode>(*payload->getNick()));
        mixElement.addNode(nickElement);
    }

    if (payload->getJID()) {
        std::shared_ptr<XMLElement> jidElement = std::make_shared<XMLElement>("jid");
        jidElement->addNode(std::make_shared<XMLTextNode>(*payload->getJID()));
        mixElement.addNode(jidElement);
    }

    if (payload->getSubmissionID()) {
        std::shared_ptr<XMLElement> subIDElement = std::make_shared<XMLElement>("submission-id");
        subIDElement->addNode(std::make_shared<XMLTextNode>(*payload->getSubmissionID()));
        mixElement.addNode(subIDElement);
    }

    return mixElement.serialize();
}

}
