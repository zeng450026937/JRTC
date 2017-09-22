#include <JXMPP/Parser/PayloadParsers/NicknameParser.h>

namespace JXMPP {

NicknameParser::NicknameParser() : level(0) {
}

void NicknameParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    ++level;
}

void NicknameParser::handleEndElement(const std::string&, const std::string&) {
    --level;
    if (level == 0) {
        getPayloadInternal()->setNickname(text);
    }
}

void NicknameParser::handleCharacterData(const std::string& data) {
    text += data;
}

}
