#include <JXMPP/Serializer/PayloadSerializers/PubSubItemsSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubItemSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubItemsSerializer::PubSubItemsSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

PubSubItemsSerializer::~PubSubItemsSerializer() {
}

std::string PubSubItemsSerializer::serializePayload(std::shared_ptr<PubSubItems> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("items", "http://jabber.org/protocol/pubsub");
    if (payload->getNode().empty()) {
        JXMPP_LOG(warning) << "Serializing PubSubItems with empty node attribute";
    }
    element.setAttribute("node", payload->getNode());
    for (const auto& item : payload->getItems()) {
        element.addNode(std::make_shared<XMLRawTextNode>(PubSubItemSerializer(serializers).serialize(item)));
    }
    if (payload->getMaximumItems()) {
        element.setAttribute("max_items", boost::lexical_cast<std::string>(*payload->getMaximumItems()));
    }
    if (payload->getSubscriptionID()) {
        element.setAttribute("subid", *payload->getSubscriptionID());
    }
    return element.serialize();
}
