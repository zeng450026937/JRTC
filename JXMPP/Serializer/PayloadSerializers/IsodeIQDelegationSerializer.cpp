#include <JXMPP/Serializer/PayloadSerializers/IsodeIQDelegationSerializer.h>

#include <memory>

#include <JXMPP/Serializer/PayloadSerializerCollection.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLRawTextNode.h>

using namespace JXMPP;

IsodeIQDelegationSerializer::IsodeIQDelegationSerializer(PayloadSerializerCollection* serializers) : serializers(serializers) {
}

IsodeIQDelegationSerializer::~IsodeIQDelegationSerializer() {
}

std::string IsodeIQDelegationSerializer::serializePayload(std::shared_ptr<IsodeIQDelegation> payload) const {
    if (!payload) {
        return "";
    }
    XMLElement element("delegate", "http://isode.com/iq_delegation");
    element.addNode(std::make_shared<XMLRawTextNode>(serializers->getPayloadSerializer(payload->getForward())->serialize(payload->getForward())));
    return element.serialize();
}
