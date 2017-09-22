#include <JXMPP/Parser/PayloadParsers/BodyParser.h>

namespace JXMPP {

BodyParser::BodyParser() : level_(0) {
}

void BodyParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    ++level_;
}

void BodyParser::handleEndElement(const std::string&, const std::string&) {
    --level_;
    if (level_ == 0) {
        getPayloadInternal()->setText(text_);
    }
}

void BodyParser::handleCharacterData(const std::string& data) {
    text_ += data;
}

}
