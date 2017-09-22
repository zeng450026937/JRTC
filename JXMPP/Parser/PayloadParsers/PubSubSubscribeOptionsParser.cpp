#include <JXMPP/Parser/PayloadParsers/PubSubSubscribeOptionsParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>

using namespace JXMPP;

PubSubSubscribeOptionsParser::PubSubSubscribeOptionsParser(PayloadParserFactoryCollection* /*parsers*/) : level(0) {
}

PubSubSubscribeOptionsParser::~PubSubSubscribeOptionsParser() {
}

void PubSubSubscribeOptionsParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void PubSubSubscribeOptionsParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {
            if (element == "required") {
                getPayloadInternal()->setRequired(true);
            }
            currentPayloadParser.reset();
        }
    }
}

void PubSubSubscribeOptionsParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}
