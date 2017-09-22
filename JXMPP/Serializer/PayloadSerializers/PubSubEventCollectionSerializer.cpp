#include <JXMPP/Serializer/PayloadSerializers/PubSubEventCollectionSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventAssociateSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventDisassociateSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubEventCollectionSerializer::PubSubEventCollectionSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubEventCollectionSerializer::~PubSubEventCollectionSerializer() {
}

std::string PubSubEventCollectionSerializer::serializePayload(std::shared_ptr<PubSubEventCollection> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("collection", "http://jabber.org/protocol/pubsub#event");
    if (payload->getNode()) {
        element.setAttribute("node", *payload->getNode());
    }
    element.addNode(std::make_shared<XMLRawTextNode>(PubSubEventDisassociateSerializer(serializers).serialize(payload->getDisassociate())));
    element.addNode(std::make_shared<XMLRawTextNode>(PubSubEventAssociateSerializer(serializers).serialize(payload->getAssociate())));
    return element.serialize();
}
