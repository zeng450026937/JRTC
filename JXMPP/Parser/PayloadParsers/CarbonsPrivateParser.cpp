#include <JXMPP/Parser/PayloadParsers/CarbonsPrivateParser.h>

namespace JXMPP {

    CarbonsPrivateParser::CarbonsPrivateParser() : GenericPayloadParser<CarbonsPrivate>() {
    }

    CarbonsPrivateParser::~CarbonsPrivateParser() {
    }

    void CarbonsPrivateParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    }

    void CarbonsPrivateParser::handleEndElement(const std::string&, const std::string&) {
    }

    void CarbonsPrivateParser::handleCharacterData(const std::string&) {
    }

}
