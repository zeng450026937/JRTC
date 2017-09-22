#include <JXMPP/Parser/PayloadParsers/DelayParser.h>

#include <JXMPP/Base/DateTime.h>

namespace JXMPP {

DelayParser::DelayParser() : level_(0) {
}

void DelayParser::handleStartElement(const std::string& /*element*/, const std::string& /*ns*/, const AttributeMap& attributes) {
    if (level_ == 0) {
        boost::posix_time::ptime stamp = stringToDateTime(attributes.getAttribute("stamp"));
        getPayloadInternal()->setStamp(stamp);
        if (!attributes.getAttribute("from").empty()) {
            std::string from = attributes.getAttribute("from");
            getPayloadInternal()->setFrom(JID(from));
        }
    }
    ++level_;
}

void DelayParser::handleEndElement(const std::string&, const std::string&) {
    --level_;
}

void DelayParser::handleCharacterData(const std::string&) {

}

}
