#include <JXMPP/Parser/PayloadParsers/PubSubEventItemsParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>
#include <JXMPP/Parser/PayloadParsers/PubSubEventItemParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubEventRetractParser.h>

using namespace JXMPP;

PubSubEventItemsParser::PubSubEventItemsParser(PayloadParserFactoryCollection* parsers) : parsers(parsers), level(0) {
}

PubSubEventItemsParser::~PubSubEventItemsParser() {
}

void PubSubEventItemsParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level == 0) {
        if (boost::optional<std::string> attributeValue = attributes.getAttributeValue("node")) {
            getPayloadInternal()->setNode(*attributeValue);
        }
    }

    if (level == 1) {
        if (element == "item" && ns == "http://jabber.org/protocol/pubsub#event") {
            currentPayloadParser = std::make_shared<PubSubEventItemParser>(parsers);
        }
        if (element == "retract" && ns == "http://jabber.org/protocol/pubsub#event") {
            currentPayloadParser = std::make_shared<PubSubEventRetractParser>(parsers);
        }
    }

    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void PubSubEventItemsParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {
            if (element == "item" && ns == "http://jabber.org/protocol/pubsub#event") {
                getPayloadInternal()->addItem(std::dynamic_pointer_cast<PubSubEventItem>(currentPayloadParser->getPayload()));
            }
            if (element == "retract" && ns == "http://jabber.org/protocol/pubsub#event") {
                getPayloadInternal()->addRetract(std::dynamic_pointer_cast<PubSubEventRetract>(currentPayloadParser->getPayload()));
            }
            currentPayloadParser.reset();
        }
    }
}

void PubSubEventItemsParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}
