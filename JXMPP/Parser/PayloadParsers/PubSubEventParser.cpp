#include <JXMPP/Parser/PayloadParsers/PubSubEventParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>
#include <JXMPP/Parser/PayloadParsers/PubSubEventCollectionParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubEventConfigurationParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubEventDeleteParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubEventItemsParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubEventPurgeParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubEventSubscriptionParser.h>

using namespace JXMPP;

PubSubEventParser::PubSubEventParser(PayloadParserFactoryCollection* parsers) : parsers(parsers), level(0) {
}

PubSubEventParser::~PubSubEventParser() {
}

void PubSubEventParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {


    if (level == 1) {
        if (element == "items" && ns == "http://jabber.org/protocol/pubsub#event") {
            currentPayloadParser = std::make_shared<PubSubEventItemsParser>(parsers);
        }
        if (element == "collection" && ns == "http://jabber.org/protocol/pubsub#event") {
            currentPayloadParser = std::make_shared<PubSubEventCollectionParser>(parsers);
        }
        if (element == "purge" && ns == "http://jabber.org/protocol/pubsub#event") {
            currentPayloadParser = std::make_shared<PubSubEventPurgeParser>(parsers);
        }
        if (element == "configuration" && ns == "http://jabber.org/protocol/pubsub#event") {
            currentPayloadParser = std::make_shared<PubSubEventConfigurationParser>(parsers);
        }
        if (element == "delete" && ns == "http://jabber.org/protocol/pubsub#event") {
            currentPayloadParser = std::make_shared<PubSubEventDeleteParser>(parsers);
        }
        if (element == "subscription" && ns == "http://jabber.org/protocol/pubsub#event") {
            currentPayloadParser = std::make_shared<PubSubEventSubscriptionParser>(parsers);
        }
    }

    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void PubSubEventParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {
            if (currentPayloadParser) {
                getPayloadInternal()->setPayload(std::dynamic_pointer_cast<PubSubEventPayload>(currentPayloadParser->getPayload()));
            }
            currentPayloadParser.reset();
        }
    }
}

void PubSubEventParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}
