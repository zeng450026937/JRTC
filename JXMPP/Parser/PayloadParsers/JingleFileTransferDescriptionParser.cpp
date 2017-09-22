/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Parser/PayloadParsers/JingleFileTransferDescriptionParser.h>

#include <boost/lexical_cast.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Base/DateTime.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>
#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

JingleFileTransferDescriptionParser::JingleFileTransferDescriptionParser(PayloadParserFactoryCollection* factories) :   factories(factories), level(0) {
}

void JingleFileTransferDescriptionParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
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

void JingleFileTransferDescriptionParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleEndElement(element, ns);
    }

    if (level == 0) {
        std::shared_ptr<JingleFileTransferFileInfo> info = std::dynamic_pointer_cast<JingleFileTransferFileInfo>(currentPayloadParser->getPayload());
        if (info) {
            getPayloadInternal()->setFileInfo(*info);
        }
    }
}

void JingleFileTransferDescriptionParser::handleCharacterData(const std::string& data) {
    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}

}
