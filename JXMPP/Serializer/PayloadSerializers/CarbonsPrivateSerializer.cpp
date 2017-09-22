#include <JXMPP/Serializer/PayloadSerializers/CarbonsPrivateSerializer.h>

#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    CarbonsPrivateSerializer::CarbonsPrivateSerializer() : GenericPayloadSerializer<CarbonsPrivate>() {
    }

    CarbonsPrivateSerializer::~CarbonsPrivateSerializer() {

    }

    std::string CarbonsPrivateSerializer::serializePayload(std::shared_ptr<CarbonsPrivate>)    const {
        XMLElement element("private", "urn:xmpp:carbons:2");
        return element.serialize();
    }
}
