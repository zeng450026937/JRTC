#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerSubscriptionSerializer.h>

#include <cassert>

#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

PubSubOwnerSubscriptionSerializer::PubSubOwnerSubscriptionSerializer(PayloadSerializerCollection* /*serializers*/) {
}

PubSubOwnerSubscriptionSerializer::~PubSubOwnerSubscriptionSerializer() {
}

std::string PubSubOwnerSubscriptionSerializer::serializePayload(std::shared_ptr<PubSubOwnerSubscription> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("subscription", "http://jabber.org/protocol/pubsub#owner");
    element.setAttribute("jid", payload->getJID());
    element.setAttribute("subscription", serializeSubscriptionType(payload->getSubscription()));
    return element.serialize();
}

std::string PubSubOwnerSubscriptionSerializer::serializeSubscriptionType(PubSubOwnerSubscription::SubscriptionType value) {
    switch (value) {
        case PubSubOwnerSubscription::None: return "none";
        case PubSubOwnerSubscription::Pending: return "pending";
        case PubSubOwnerSubscription::Subscribed: return "subscribed";
        case PubSubOwnerSubscription::Unconfigured: return "unconfigured";
    }
    assert(false);
    return "";
}
