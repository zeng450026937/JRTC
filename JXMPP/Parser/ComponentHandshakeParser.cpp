#include <JXMPP/Parser/ComponentHandshakeParser.h>

#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

ComponentHandshakeParser::ComponentHandshakeParser() : GenericElementParser<ComponentHandshake>(), depth(0) {
}

void ComponentHandshakeParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    ++depth;
}

void ComponentHandshakeParser::handleEndElement(const std::string&, const std::string&) {
    --depth;
    if (depth == 0) {
        getElementGeneric()->setData(text);
    }
}

void ComponentHandshakeParser::handleCharacterData(const std::string& text) {
    this->text += text;
}

}
