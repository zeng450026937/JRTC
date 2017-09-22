#include <JXMPP/Serializer/PayloadSerializers/DiscoInfoSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

namespace JXMPP {

DiscoInfoSerializer::DiscoInfoSerializer() : GenericPayloadSerializer<DiscoInfo>() {
}

std::string DiscoInfoSerializer::serializePayload(std::shared_ptr<DiscoInfo> discoInfo)  const {
    XMLElement queryElement("query", "http://jabber.org/protocol/disco#info");
    if (!discoInfo->getNode().empty()) {
        queryElement.setAttribute("node", discoInfo->getNode());
    }
    for (const auto& identity : discoInfo->getIdentities()) {
        std::shared_ptr<XMLElement> identityElement(new XMLElement("identity"));
        if (!identity.getLanguage().empty()) {
            identityElement->setAttribute("xml:lang", identity.getLanguage());
        }
        identityElement->setAttribute("category", identity.getCategory());
        identityElement->setAttribute("name", identity.getName());
        identityElement->setAttribute("type", identity.getType());
        queryElement.addNode(identityElement);
    }
    for (const auto& feature : discoInfo->getFeatures()) {
        std::shared_ptr<XMLElement> featureElement(new XMLElement("feature"));
        featureElement->setAttribute("var", feature);
        queryElement.addNode(featureElement);
    }
    for (const auto& extension : discoInfo->getExtensions()) {
        queryElement.addNode(std::make_shared<XMLRawTextNode>(FormSerializer().serialize(extension)));
    }
    return queryElement.serialize();
}

}
