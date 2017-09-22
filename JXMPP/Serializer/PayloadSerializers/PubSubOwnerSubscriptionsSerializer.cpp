#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerSubscriptionsSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerSubscriptionSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubOwnerSubscriptionsSerializer::PubSubOwnerSubscriptionsSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubOwnerSubscriptionsSerializer::~PubSubOwnerSubscriptionsSerializer() {
}

std::string PubSubOwnerSubscriptionsSerializer::serializePayload(std::shared_ptr<PubSubOwnerSubscriptions> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("subscriptions", "http://jabber.org/protocol/pubsub#owner");
    element.setAttribute("node", payload->getNode());
    for (const auto& item : payload->getSubscriptions()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubOwnerSubscriptionSerializer(serializers).serialize(item)));
    }
    return element.serialize();
}
