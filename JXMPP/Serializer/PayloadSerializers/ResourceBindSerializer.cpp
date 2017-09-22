#include <JXMPP/Serializer/PayloadSerializers/ResourceBindSerializer.h>

#include <memory>

#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {

ResourceBindSerializer::ResourceBindSerializer() : GenericPayloadSerializer<ResourceBind>() {
}

std::string ResourceBindSerializer::serializePayload(std::shared_ptr<ResourceBind> resourceBind)  const {
    XMLElement bindElement("bind", "urn:ietf:params:xml:ns:xmpp-bind");
    if (resourceBind->getJID().isValid()) {
        std::shared_ptr<XMLElement> jidNode(new XMLElement("jid"));
        jidNode->addNode(std::make_shared<XMLTextNode>(resourceBind->getJID().toString()));
        bindElement.addNode(jidNode);
    }
    else if (!resourceBind->getResource().empty()) {
        std::shared_ptr<XMLElement> resourceNode(new XMLElement("resource"));
        resourceNode->addNode(std::make_shared<XMLTextNode>(resourceBind->getResource()));
        bindElement.addNode(resourceNode);
    }
    return bindElement.serialize();
}

}
