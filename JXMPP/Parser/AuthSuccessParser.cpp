#include <JXMPP/Parser/AuthSuccessParser.h>

#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

AuthSuccessParser::AuthSuccessParser() : GenericElementParser<AuthSuccess>(), depth(0) {
}

void AuthSuccessParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    ++depth;
}

void AuthSuccessParser::handleEndElement(const std::string&, const std::string&) {
    --depth;
    if (depth == 0) {
        getElementGeneric()->setValue(Base64::decode(text));
    }
}

void AuthSuccessParser::handleCharacterData(const std::string& text) {
    this->text += text;
}

}
