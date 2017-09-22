#include <JXMPP/Parser/PresenceParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Base/Log.h>

namespace JXMPP {

PresenceParser::PresenceParser(PayloadParserFactoryCollection* factories) :
        GenericStanzaParser<Presence>(factories) {
}

void PresenceParser::handleStanzaAttributes(const AttributeMap& attributes) {
    boost::optional<std::string> type = attributes.getAttributeValue("type");
    if (type) {
        if (*type == "unavailable") {
            getStanzaGeneric()->setType(Presence::Unavailable);
        }
        else if (*type == "probe") {
            getStanzaGeneric()->setType(Presence::Probe);
        }
        else if (*type == "subscribe") {
            getStanzaGeneric()->setType(Presence::Subscribe);
        }
        else if (*type == "subscribed") {
            getStanzaGeneric()->setType(Presence::Subscribed);
        }
        else if (*type == "unsubscribe") {
            getStanzaGeneric()->setType(Presence::Unsubscribe);
        }
        else if (*type == "unsubscribed") {
            getStanzaGeneric()->setType(Presence::Unsubscribed);
        }
        else if (*type == "error") {
            getStanzaGeneric()->setType(Presence::Error);
        }
        else {
            JXMPP_LOG(error) << "Unknown Presence type: " << *type << std::endl;
            getStanzaGeneric()->setType(Presence::Available);
        }
    }
    else {
        getStanzaGeneric()->setType(Presence::Available);
    }
}

}
