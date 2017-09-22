/*
 * Copyright (c) 2013 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Parser/PayloadParsers/IdleParser.h>

#include <JXMPP/Base/DateTime.h>

namespace JXMPP {

IdleParser::IdleParser() : level_(0) {
}

void IdleParser::handleStartElement(const std::string& /*element*/, const std::string& /*ns*/, const AttributeMap& attributes) {
    if (level_ == 0) {
        boost::posix_time::ptime since = stringToDateTime(attributes.getAttribute("since"));
        getPayloadInternal()->setSince(since);
    }
    ++level_;
}

void IdleParser::handleEndElement(const std::string&, const std::string&) {
    --level_;
}

void IdleParser::handleCharacterData(const std::string&) {

}

}
