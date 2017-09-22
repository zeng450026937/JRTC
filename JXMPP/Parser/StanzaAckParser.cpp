#include <JXMPP/Parser/StanzaAckParser.h>

#include <boost/lexical_cast.hpp>

namespace JXMPP {

StanzaAckParser::StanzaAckParser() : GenericElementParser<StanzaAck>(), depth(0) {
}

void StanzaAckParser::handleStartElement(const std::string&, const std::string&, const AttributeMap& attributes) {
    if (depth == 0) {
        std::string handledStanzasString = attributes.getAttribute("h");
        try {
            getElementGeneric()->setHandledStanzasCount(boost::lexical_cast<int>(handledStanzasString));
        }
        catch (const boost::bad_lexical_cast &) {
        }
    }
    ++depth;
}

void StanzaAckParser::handleEndElement(const std::string&, const std::string&) {
    --depth;
}

}
