/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Serializer/PayloadSerializers/MIXUpdateSubscriptionSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/FormSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

namespace JXMPP {

MIXUpdateSubscriptionSerializer::MIXUpdateSubscriptionSerializer() {
}

MIXUpdateSubscriptionSerializer::~MIXUpdateSubscriptionSerializer() {
}

std::string MIXUpdateSubscriptionSerializer::serializePayload(std::shared_ptr<MIXUpdateSubscription> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("update-subscription", "urn:xmpp:mix:0");
    if (payload->getJID()) {
        element.setAttribute("jid", *payload->getJID());
    }
    auto subscriptionData = payload->getSubscriptions();
    std::vector<std::string> subscriptions(subscriptionData.begin(), subscriptionData.end());
    std::sort(subscriptions.begin(), subscriptions.end());

    for (const auto& item : subscriptions) {
        auto subscribeElement = std::make_shared<XMLElement>("subscribe");
        subscribeElement->setAttribute("node", item);
        element.addNode(subscribeElement);
    }
    return element.serialize();
}

}
