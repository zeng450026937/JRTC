#include <JXMPP/Serializer/PayloadSerializers/PubSubEventSubscriptionSerializer.h>

#include <JXMPP/Base/DateTime.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubEventSubscriptionSerializer::PubSubEventSubscriptionSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubEventSubscriptionSerializer::~PubSubEventSubscriptionSerializer() {
}

std::string PubSubEventSubscriptionSerializer::serializePayload(std::shared_ptr<PubSubEventSubscription> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("subscription", "http://jabber.org/protocol/pubsub#event");
    element.setAttribute("node", payload->getNode());
    element.setAttribute("jid", payload->getJID());
    element.setAttribute("subscription", serializeSubscriptionType(payload->getSubscription()));
    if (payload->getSubscriptionID()) {
        element.setAttribute("subid", *payload->getSubscriptionID());
    }
    element.setAttribute("expiry", dateTimeToString(payload->getExpiry()));
    return element.serialize();
}

std::string PubSubEventSubscriptionSerializer::serializeSubscriptionType(PubSubEventSubscription::SubscriptionType value) {
    switch (value) {
        case PubSubEventSubscription::None: return "none";
        case PubSubEventSubscription::Pending: return "pending";
        case PubSubEventSubscription::Subscribed: return "subscribed";
        case PubSubEventSubscription::Unconfigured: return "unconfigured";
    }
    assert(false);
    return "";
}
