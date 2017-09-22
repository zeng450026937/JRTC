#include <JXMPP/Parser/PayloadParsers/PubSubOwnerAffiliationsParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>
#include <JXMPP/Parser/PayloadParsers/PubSubOwnerAffiliationParser.h>

using namespace JXMPP;

PubSubOwnerAffiliationsParser::PubSubOwnerAffiliationsParser(PayloadParserFactoryCollection* parsers) : parsers(parsers), level(0) {
}

PubSubOwnerAffiliationsParser::~PubSubOwnerAffiliationsParser() {
}

void PubSubOwnerAffiliationsParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level == 0) {
        if (boost::optional<std::string> attributeValue = attributes.getAttributeValue("node")) {
            getPayloadInternal()->setNode(*attributeValue);
        }
    }

    if (level == 1) {
        if (element == "affiliation" && ns == "http://jabber.org/protocol/pubsub#owner") {
            currentPayloadParser = std::make_shared<PubSubOwnerAffiliationParser>(parsers);
        }
    }

    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void PubSubOwnerAffiliationsParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {
            if (element == "affiliation" && ns == "http://jabber.org/protocol/pubsub#owner") {
                getPayloadInternal()->addAffiliation(std::dynamic_pointer_cast<PubSubOwnerAffiliation>(currentPayloadParser->getPayload()));
            }
            currentPayloadParser.reset();
        }
    }
}

void PubSubOwnerAffiliationsParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}
