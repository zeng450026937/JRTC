#include <JXMPP/Parser/AuthRequestParser.h>

#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

AuthRequestParser::AuthRequestParser() : GenericElementParser<AuthRequest>(), depth_(0) {
}

void AuthRequestParser::handleStartElement(const std::string&, const std::string&, const AttributeMap& attribute) {
    if (depth_ == 0) {
        getElementGeneric()->setMechanism(attribute.getAttribute("mechanism"));
    }
    ++depth_;
}

void AuthRequestParser::handleEndElement(const std::string&, const std::string&) {
    --depth_;
    if (depth_ == 0) {
        getElementGeneric()->setMessage(createSafeByteArray(Base64::decode(text_)));
    }
}

void AuthRequestParser::handleCharacterData(const std::string& text) {
    text_ += text;
}

}
