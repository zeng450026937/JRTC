#include <JXMPP/Parser/PayloadParsers/CarbonsEnableParser.h>

namespace JXMPP {

    CarbonsEnableParser::CarbonsEnableParser() : GenericPayloadParser<CarbonsEnable>() {
    }

    CarbonsEnableParser::~CarbonsEnableParser() {
    }

    void CarbonsEnableParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    }

    void CarbonsEnableParser::handleEndElement(const std::string&, const std::string&) {
    }

    void CarbonsEnableParser::handleCharacterData(const std::string&) {
    }

}
