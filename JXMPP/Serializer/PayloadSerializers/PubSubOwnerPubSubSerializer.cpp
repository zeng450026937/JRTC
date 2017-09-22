#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerPubSubSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerAffiliationsSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerConfigureSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerDefaultSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerDeleteSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerPurgeSerializer.h>
#include <JXMPP/Serializer/PayloadSerializers/PubSubOwnerSubscriptionsSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

PubSubOwnerPubSubSerializer::PubSubOwnerPubSubSerializer(PayloadSerializerCollection* serializers) {
    pubsubSerializers.push_back(std::make_shared<PubSubOwnerConfigureSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubOwnerSubscriptionsSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubOwnerDefaultSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubOwnerPurgeSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubOwnerAffiliationsSerializer>(serializers));
    pubsubSerializers.push_back(std::make_shared<PubSubOwnerDeleteSerializer>(serializers));
}

PubSubOwnerPubSubSerializer::~PubSubOwnerPubSubSerializer() {
}

std::string PubSubOwnerPubSubSerializer::serializePayload(std::shared_ptr<PubSubOwnerPubSub> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("pubsub", "http://jabber.org/protocol/pubsub#owner");
    std::shared_ptr<PubSubOwnerPayload> p = payload->getPayload();
    for (const auto& serializer : pubsubSerializers) {
        if (serializer->canSerialize(p)) {
            element.addNode(std::make_shared<XMLRawTextNode>(serializer->serialize(p)));
        }
    }
    return element.serialize();
}
