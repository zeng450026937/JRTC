#include <JXMPP/Serializer/PayloadSerializers/MUCAdminPayloadSerializer.h>

#include <memory>
#include <sstream>

#include <JXMPP/Serializer/PayloadSerializers/MUCItemSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

MUCAdminPayloadSerializer::MUCAdminPayloadSerializer() : GenericPayloadSerializer<MUCAdminPayload>() {
}

std::string MUCAdminPayloadSerializer::serializePayload(std::shared_ptr<MUCAdminPayload> payload)  const {
    XMLElement mucElement("query", "http://jabber.org/protocol/muc#admin");
    for (const auto& item : payload->getItems()) {
        mucElement.addNode(MUCItemSerializer::itemToElement(item));
    }
    return mucElement.serialize();
}


}
