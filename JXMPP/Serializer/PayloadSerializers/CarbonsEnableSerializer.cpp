#include <JXMPP/Serializer/PayloadSerializers/CarbonsEnableSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    CarbonsEnableSerializer::CarbonsEnableSerializer() : GenericPayloadSerializer<CarbonsEnable>() {
    }

    CarbonsEnableSerializer::~CarbonsEnableSerializer() {

    }

    std::string CarbonsEnableSerializer::serializePayload(std::shared_ptr<CarbonsEnable>)    const {
        XMLElement element("enable", "urn:xmpp:carbons:2");
        return element.serialize();
    }
}
