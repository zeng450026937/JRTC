#include <JXMPP/Parser/PayloadParsers/PubSubOwnerDefaultParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/FormParser.h>

using namespace JXMPP;

PubSubOwnerDefaultParser::PubSubOwnerDefaultParser(PayloadParserFactoryCollection* /*parsers*/) : level(0) {
}

PubSubOwnerDefaultParser::~PubSubOwnerDefaultParser() {
}

void PubSubOwnerDefaultParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level == 1) {
        if (element == "x" && ns == "jabber:x:data") {
            currentPayloadParser = std::make_shared<FormParser>();
        }
    }

    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void PubSubOwnerDefaultParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {
            if (element == "x" && ns == "jabber:x:data") {
                getPayloadInternal()->setData(std::dynamic_pointer_cast<Form>(currentPayloadParser->getPayload()));
            }
            currentPayloadParser.reset();
        }
    }
}

void PubSubOwnerDefaultParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}
