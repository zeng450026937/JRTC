#include <JXMPP/Serializer/PayloadSerializers/SoftwareVersionSerializer.h>

namespace JXMPP {

SoftwareVersionSerializer::SoftwareVersionSerializer() : GenericPayloadSerializer<SoftwareVersion>() {
}

std::string SoftwareVersionSerializer::serializePayload(std::shared_ptr<SoftwareVersion> version)  const {
    std::string result("<query xmlns=\"jabber:iq:version\">");
    if (!version->getName().empty()) {
        result += "<name>" + version->getName() + "</name>";
    }
    if (!version->getVersion().empty()) {
        result += "<version>" + version->getVersion() + "</version>";
    }
    if (!version->getOS().empty()) {
        result += "<os>" + version->getOS() + "</os>";
    }
    result += "</query>";
    return result;
}

}