#include <JXMPP/Parser/PayloadParsers/SubjectParser.h>

namespace JXMPP {

SubjectParser::SubjectParser() : level_(0) {
}

void SubjectParser::handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
    ++level_;
}

void SubjectParser::handleEndElement(const std::string&, const std::string&) {
    --level_;
    if (level_ == 0) {
        getPayloadInternal()->setText(text_);
    }
}

void SubjectParser::handleCharacterData(const std::string& data) {
    if (level_ == 1) {
        text_ += data;
    }
}

}
