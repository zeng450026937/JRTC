#include <JXMPP/Parser/AuthResponseParser.h>

#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

AuthResponseParser::AuthResponseParser() : GenericElementParser<AuthResponse>(), depth(0) {
}

void AuthResponseParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    ++depth;
}

void AuthResponseParser::handleEndElement(const std::string&, const std::string&) {
    --depth;
    if (depth == 0) {
        getElementGeneric()->setValue(createSafeByteArray(Base64::decode(text)));
    }
}

void AuthResponseParser::handleCharacterData(const std::string& text) {
    this->text += text;
}

}
