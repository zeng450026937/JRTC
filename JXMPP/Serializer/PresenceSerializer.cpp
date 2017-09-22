#include <JXMPP/Serializer/PresenceSerializer.h>

#include <memory>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {

PresenceSerializer::PresenceSerializer(PayloadSerializerCollection* payloadSerializers, const boost::optional<std::string>& explicitNS) :
        GenericStanzaSerializer<Presence>("presence", payloadSerializers, explicitNS) {

}

void PresenceSerializer::setStanzaSpecificAttributesGeneric(
        std::shared_ptr<Presence> presence,
        XMLElement& element) const {
    switch (presence->getType()) {
        case Presence::Unavailable: element.setAttribute("type","unavailable"); break;
        case Presence::Probe: element.setAttribute("type","probe"); break;
        case Presence::Subscribe: element.setAttribute("type","subscribe"); break;
        case Presence::Subscribed: element.setAttribute("type","subscribed"); break;
        case Presence::Unsubscribe: element.setAttribute("type","unsubscribe"); break;
        case Presence::Unsubscribed: element.setAttribute("type","unsubscribed"); break;
        case Presence::Error: element.setAttribute("type","error"); break;
        case Presence::Available: break;
    }
}

}
