#include <JXMPP/Parser/PayloadParsers/RawXMLPayloadParser.h>

#include <JXMPP/Parser/SerializingParser.h>

namespace JXMPP {

RawXMLPayloadParser::RawXMLPayloadParser() : level_(0) {
}

void RawXMLPayloadParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    ++level_;
    serializingParser_.handleStartElement(element, ns, attributes);
}

void RawXMLPayloadParser::handleEndElement(const std::string& element, const std::string& ns) {
    serializingParser_.handleEndElement(element, ns);
    --level_;
    if (level_ == 0) {
        getPayloadInternal()->setRawXML(serializingParser_.getResult());
    }
}

void RawXMLPayloadParser::handleCharacterData(const std::string& data) {
    serializingParser_.handleCharacterData(data);
}

}
