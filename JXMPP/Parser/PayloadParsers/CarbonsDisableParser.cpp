#include <JXMPP/Parser/PayloadParsers/CarbonsDisableParser.h>

namespace JXMPP {

    CarbonsDisableParser::CarbonsDisableParser() : GenericPayloadParser<CarbonsDisable>() {
    }

    CarbonsDisableParser::~CarbonsDisableParser() {
    }

    void CarbonsDisableParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    }

    void CarbonsDisableParser::handleEndElement(const std::string&, const std::string&) {
    }

    void CarbonsDisableParser::handleCharacterData(const std::string&) {
    }

}
