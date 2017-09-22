#include <JXMPP/Parser/PayloadParsers/StatusParser.h>

namespace JXMPP {

StatusParser::StatusParser() : level_(0) {
}

void StatusParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    ++level_;
}

void StatusParser::handleEndElement(const std::string&, const std::string&) {
    --level_;
    if (level_ == 0) {
        getPayloadInternal()->setText(text_);
    }
}

void StatusParser::handleCharacterData(const std::string& data) {
    text_ += data;
}

}
