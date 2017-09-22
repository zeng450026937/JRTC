#include <JXMPP/Serializer/PayloadSerializers/MUCDestroyPayloadSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

MUCDestroyPayloadSerializer::MUCDestroyPayloadSerializer() : GenericPayloadSerializer<MUCDestroyPayload>() {
}

std::string MUCDestroyPayloadSerializer::serializePayload(std::shared_ptr<MUCDestroyPayload> payload)  const {
    XMLElement mucElement("destroy", "");
    if (!payload->getReason().empty()) {
        XMLElement::ref reason = std::make_shared<XMLElement>("reason", "");
        reason->addNode(std::make_shared<XMLTextNode>(payload->getReason()));
        mucElement.addNode(reason);
    }
    if (payload->getNewVenue().isValid()) {
        mucElement.setAttribute("jid", payload->getNewVenue().toString());
    }
    return mucElement.serialize();
}




}
