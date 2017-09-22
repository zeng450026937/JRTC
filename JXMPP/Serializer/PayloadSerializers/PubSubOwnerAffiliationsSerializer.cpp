#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerAffiliationsSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerAffiliationSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubOwnerAffiliationsSerializer::PubSubOwnerAffiliationsSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubOwnerAffiliationsSerializer::~PubSubOwnerAffiliationsSerializer() {
}

std::string PubSubOwnerAffiliationsSerializer::serializePayload(std::shared_ptr<PubSubOwnerAffiliations> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("affiliations", "http://jabber.org/protocol/pubsub#owner");
    element.setAttribute("node", payload->getNode());
    for (const auto& item : payload->getAffiliations()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubOwnerAffiliationSerializer(serializers).serialize(item)));
    }
    return element.serialize();
}
