/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Parser/PayloadParsers/JingleIBBTransportMethodPayloadParser.h>

#include <boost/lexical_cast.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Base/Log.h>

namespace JXMPP {
    JingleIBBTransportMethodPayloadParser::JingleIBBTransportMethodPayloadParser() : level(0) {

    }

    void JingleIBBTransportMethodPayloadParser::handleStartElement(const std::string&, const std::string&, const AttributeMap& attributes) {
        try {
            boost::optional<std::string> blockSize = attributes.getAttributeValue("block-size");
            if (blockSize) {
                getPayloadInternal()->setBlockSize(boost::lexical_cast<unsigned int>(*blockSize));
            }
        }
        catch (boost::bad_lexical_cast &) {
        }
        getPayloadInternal()->setSessionID(attributes.getAttributeValue("sid").get_value_or(""));
        ++level;
    }

    void JingleIBBTransportMethodPayloadParser::handleEndElement(const std::string&, const std::string&) {
        --level;


    }

    void JingleIBBTransportMethodPayloadParser::handleCharacterData(const std::string&) {

    }
}
