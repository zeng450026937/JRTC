#include <JXMPP/Serializer/PayloadSerializers/PubSubAffiliationsSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubAffiliationSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubAffiliationsSerializer::PubSubAffiliationsSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubAffiliationsSerializer::~PubSubAffiliationsSerializer() {
}

std::string PubSubAffiliationsSerializer::serializePayload(std::shared_ptr<PubSubAffiliations> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("affiliations", "http://jabber.org/protocol/pubsub");
    if (payload->getNode()) {
        element.setAttribute("node", *payload->getNode());
    }
    for (const auto& item : payload->getAffiliations()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubAffiliationSerializer(serializers).serialize(item)));
    }
    return element.serialize();
}
