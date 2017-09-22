/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Parser/PayloadParsers/JingleFileTransferHashParser.h>

#include <memory>

#include <boost/algorithm/string.hpp>

#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/JingleFileTransferFileInfoParser.h>

namespace JXMPP {

JingleFileTransferHashParser::JingleFileTransferHashParser() : level(0) {
}

void JingleFileTransferHashParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level == 1 && element == "file") {
        currentPayloadParser = std::make_shared<JingleFileTransferFileInfoParser>();
    }

    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleStartElement(element, ns, attributes);
    }
    ++level;
}

void JingleFileTransferHashParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level;
    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleEndElement(element, ns);
    }

    if (level == 1) {
        std::shared_ptr<JingleFileTransferFileInfo> info = std::dynamic_pointer_cast<JingleFileTransferFileInfo>(currentPayloadParser->getPayload());
        if (info) {
            getPayloadInternal()->setFileInfo(*info);
        }
    }
}

void JingleFileTransferHashParser::handleCharacterData(const std::string& data) {
    if (level >= 1 && currentPayloadParser) {
        currentPayloadParser->handleCharacterData(data);
    }
}

}
