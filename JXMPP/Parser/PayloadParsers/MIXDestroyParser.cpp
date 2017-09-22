/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Parser/PayloadParsers/MIXDestroyParser.h>

#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/FormParser.h>

using namespace JXMPP;

MIXDestroyParser::MIXDestroyParser() : level_(0) {
}

MIXDestroyParser::~MIXDestroyParser() {
}

void MIXDestroyParser::handleStartElement(const std::string&, const std::string&, const AttributeMap& attributes) {
    if (level_ == 0) {
        if (boost::optional<std::string> attributeValue = attributes.getAttributeValue("channel")) {
            getPayloadInternal()->setChannel(*attributeValue);
        }
    }
    ++level_;
}

void MIXDestroyParser::handleEndElement(const std::string&, const std::string&) {
    --level_;
}

void MIXDestroyParser::handleCharacterData(const std::string&) {
}
