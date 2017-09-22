#include <JXMPP/Parser/PayloadParsers/PubSubParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>
#include <JXMPP/Parser/PayloadParsers/PubSubAffiliationsParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubConfigureParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubCreateParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubDefaultParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubItemsParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubOptionsParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubPublishParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubRetractParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubSubscribeParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubSubscriptionParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubSubscriptionsParser.h>
#include <JXMPP/Parser/PayloadParsers/PubSubUnsubscribeParser.h>

using namespace JXMPP;

PubSubParser::PubSubParser(PayloadParserFactoryCollection* parsers) : parsers(parsers), level(0) {
}

PubSubParser::~PubSubParser() {
}

void PubSubParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level == 1) {
        if (element == "items" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubItemsParser>(parsers);
        }
        if (element == "create" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubCreateParser>(parsers);
        }
        if (element == "publish" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubPublishParser>(parsers);
        }
        if (element == "affiliations" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubAffiliationsParser>(parsers);
        }
        if (element == "retract" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubRetractParser>(parsers);
        }
        if (element == "options" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubOptionsParser>(parsers);
        }
        if (element == "configure" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubConfigureParser>(parsers);
        }
        if (element == "default" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubDefaultParser>(parsers);
        }
        if (element == "subscriptions" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubSubscriptionsParser>(parsers);
        }
        if (element == "subscribe" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubSubscribeParser>(parsers);
        }
        if (element == "unsubscribe" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubUnsubscribeParser>(parsers);
        }
        if (element == "subscription" && ns == "http://jabber.org/protocol/pubsub") {
            currentPayloadParser = std::make_shared<PubSubSubscriptionParser>(parsers);
        }
    }

    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void PubSubParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {
            if (currentPayloadParser) {
                if (element == "options" && ns == "http://jabber.org/protocol/pubsub") {
                    optionsPayload = std::dynamic_pointer_cast<PubSubOptions>(currentPayloadParser->getPayload());
                }
                else if (element == "configure" && ns == "http://jabber.org/protocol/pubsub") {
                    configurePayload = std::dynamic_pointer_cast<PubSubConfigure>(currentPayloadParser->getPayload());
                }
                else {
                    getPayloadInternal()->setPayload(std::dynamic_pointer_cast<PubSubPayload>(currentPayloadParser->getPayload()));
                }
            }
            currentPayloadParser.reset();
        }

        if (level == 0) {
            if (std::shared_ptr<PubSubCreate> create = std::dynamic_pointer_cast<PubSubCreate>(getPayloadInternal()->getPayload())) {
                if (configurePayload) {
                    create->setConfigure(configurePayload);
                }
            }
            if (std::shared_ptr<PubSubSubscribe> subscribe = std::dynamic_pointer_cast<PubSubSubscribe>(getPayloadInternal()->getPayload())) {
                if (optionsPayload) {
                    subscribe->setOptions(optionsPayload);
                }
            }
        }
    }
}

void PubSubParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}
