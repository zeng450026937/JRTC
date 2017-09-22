#include <JXMPP/Parser/PayloadParsers/PubSubOwnerRedirectParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>

using namespace JXMPP;

PubSubOwnerRedirectParser::PubSubOwnerRedirectParser(PayloadParserFactoryCollection* /*parsers*/) : level(0) {
}

PubSubOwnerRedirectParser::~PubSubOwnerRedirectParser() {
}

void PubSubOwnerRedirectParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level == 0) {
        if (boost::optional<std::string> attributeValue = attributes.getAttributeValue("uri")) {
            getPayloadInternal()->setURI(*attributeValue);
        }
    }

    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void PubSubOwnerRedirectParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {

            currentPayloadParser.reset();
        }
    }
}

void PubSubOwnerRedirectParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}
