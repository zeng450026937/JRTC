#include <JXMPP/Parser/PayloadParsers/IsodeIQDelegationParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>

using namespace JXMPP;

IsodeIQDelegationParser::IsodeIQDelegationParser(PayloadParserFactoryCollection* parsers) : parsers(parsers), level(0) {
}

IsodeIQDelegationParser::~IsodeIQDelegationParser() {
}

void IsodeIQDelegationParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {


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

void IsodeIQDelegationParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (currentPayloadParser) {
        if (level >= 1) {
            currentPayloadParser->handleEndElement(element, ns);
        }

        if (level == 1) {
            getPayloadInternal()->setForward(std::dynamic_pointer_cast<Forwarded>(currentPayloadParser->getPayload()));
            currentPayloadParser.reset();
        }
    }
}

void IsodeIQDelegationParser::handleCharacterData(const std::string& data) {
    if (level > 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}
