#include <JXMPP/Serializer/PayloadSerializers/PubSubEventSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/PubSubEventCollectionSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventConfigurationSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventDeleteSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventItemsSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventPurgeSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubEventSubscriptionSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubEventSerializer::PubSubEventSerializer(PayloadSerializerCollection* serializers) {
    pubsubSerializers.push_back(std::make_shared<PubSubEventSubscriptionSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubEventPurgeSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubEventCollectionSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubEventDeleteSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubEventItemsSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubEventConfigurationSerializer>(serializers));
}

PubSubEventSerializer::~PubSubEventSerializer() {
}

std::string PubSubEventSerializer::serializePayload(std::shared_ptr<PubSubEvent> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("event", "http://jabber.org/protocol/pubsub#event");
    std::shared_ptr<PubSubEventPayload> p = payload->getPayload();
    for (const auto& serializer : pubsubSerializers) {
        if (serializer->canSerialize(p)) {
            element.addNode(std::make_shared<XMLRawTextNode>(serializer->serialize(p)));
        }
    }
    return element.serialize();
}
