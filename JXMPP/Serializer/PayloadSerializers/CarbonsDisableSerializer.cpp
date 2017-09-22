#include <JXMPP/Serializer/PayloadSerializers/CarbonsDisableSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    CarbonsDisableSerializer::CarbonsDisableSerializer() : GenericPayloadSerializer<CarbonsDisable>() {

    }

    CarbonsDisableSerializer::~CarbonsDisableSerializer() {

    }

     std::string CarbonsDisableSerializer::serializePayload(std::shared_ptr<CarbonsDisable>)    const {
        XMLElement element("disable", "urn:xmpp:carbons:2");
        return element.serialize();
    }
}
