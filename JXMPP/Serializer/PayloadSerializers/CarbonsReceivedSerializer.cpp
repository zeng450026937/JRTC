#include <JXMPP/Serializer/PayloadSerializers/CarbonsReceivedSerializer.h>

#include <memory>

namespace JXMPP {
    CarbonsReceivedSerializer::CarbonsReceivedSerializer(PayloadSerializerCollection* serializers) : GenericPayloadSerializer<CarbonsReceived>(), serializers_(serializers) {
    }

    CarbonsReceivedSerializer::~CarbonsReceivedSerializer() {
    }

    std::string CarbonsReceivedSerializer::serializePayload(std::shared_ptr<CarbonsReceived> received) const {
        XMLElement element("received", "urn:xmpp:carbons:2");
        if (received->getForwarded()) {
            element.addNode(std::make_shared<XMLRawTextNode>(ForwardedSerializer(serializers_).serialize(received->getForwarded())));
        }
        return element.serialize();
    }
}
