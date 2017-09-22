#include <JXMPP/Serializer/PayloadSerializers/PubSubSubscriptionsSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubSubscriptionSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubSubscriptionsSerializer::PubSubSubscriptionsSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubSubscriptionsSerializer::~PubSubSubscriptionsSerializer() {
}

std::string PubSubSubscriptionsSerializer::serializePayload(std::shared_ptr<PubSubSubscriptions> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("subscriptions", "http://jabber.org/protocol/pubsub");
    if (payload->getNode()) {
        element.setAttribute("node", *payload->getNode());
    }
    for (const auto& item : payload->getSubscriptions()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubSubscriptionSerializer(serializers).serialize(item)));
    }
    return element.serialize();
}
