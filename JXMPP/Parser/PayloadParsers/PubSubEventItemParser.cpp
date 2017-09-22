#include <JXMPP/Parser/PayloadParsers/PubSubEventItemParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>

using namespace JXMPP;

PubSubEventItemParser::PubSubEventItemParser(PayloadParserFactoryCollection* parsers) : parsers(parsers), level(0) {
}

PubSubEventItemParser::~PubSubEventItemParser() {
}

void PubSubEventItemParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level == 0) {
        if (boost::optional<std::string> attributeValue = attributes.getAttributeValue("node")) {
            getPayloadInternal()->setNode(*attributeValue);
        }
        if (boost::optional<std::string> attributeValue = attributes.getAttributeValue("publisher")) {
            getPayloadInternal()->setPublisher(*attributeValue);
        }
        if (boost::optional<std::string> attributeValue = attributes.getAttributeValue("id")) {
            getPayloadInternal()->setID(*attributeValue);
        }
    }

    if (level == 1) {
        if (PayloadParserFactory* factory = parsers->getPayloadParserFactory(element, ns, attributes)) {
            currentPayloadParser.reset(factory->createPayloadParser());
        }
    }

    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void PubSubEventItemParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {
            getPayloadInternal()->addData(currentPayloadParser->getPayload());
            currentPayloadParser.reset();
        }
    }
}

void PubSubEventItemParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}
