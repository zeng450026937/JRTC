#include <JXMPP/Parser/PayloadParsers/MUCOwnerPayloadParser.h>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>

namespace JXMPP {

MUCOwnerPayloadParser::MUCOwnerPayloadParser(PayloadParserFactoryCollection* factories) : factories(factories), level(0) {
}

void MUCOwnerPayloadParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level == 1) {
        PayloadParserFactory* payloadParserFactory = factories->getPayloadParserFactory(element, ns, attributes);
        if (payloadParserFactory) {
            currentPayloadParser.reset(payloadParserFactory->createPayloadParser());
        }
    }

    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void MUCOwnerPayloadParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {
            getPayloadInternal()->setPayload(currentPayloadParser->getPayload());
        }
    }
}

void MUCOwnerPayloadParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}

}
