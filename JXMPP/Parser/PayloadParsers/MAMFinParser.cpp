#include <JXMPP/Parser/PayloadParsers/MAMFinParser.h>

#include <boost/lexical_cast.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Base/DateTime.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>
#include <JXMPP/Parser/PayloadParsers/ResultSetParser.h>

using namespace JXMPP;

MAMFinParser::MAMFinParser() : level_(TopLevel) {
}

void MAMFinParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    if (level_ == TopLevel) {
        getPayloadInternal()->setComplete(attributes.getBoolAttribute("complete", false));
        getPayloadInternal()->setStable(attributes.getBoolAttribute("stable", true));
        boost::optional<std::string> attributeValue;
        if ((attributeValue = attributes.getAttributeValue("queryid"))) {
            getPayloadInternal()->setQueryID(*attributeValue);
        }
    }
    else if (level_ == PayloadLevel) {
        if (element == "set" && ns == "http://jabber.org/protocol/rsm") {
            resultSetParser_ = std::make_shared<ResultSetParser>();
        }
    }

    if (resultSetParser_) { /* parsing a nested ResultSet */
        resultSetParser_->handleStartElement(element, ns, attributes);
    }

    ++level_;
}

void MAMFinParser::handleEndElement(const std::string& element, const std::string& ns) {
    --level_;

    if (resultSetParser_ && level_ >= PayloadLevel) {
        resultSetParser_->handleEndElement(element, ns);
    }
    if (resultSetParser_ && level_ == PayloadLevel) {
        /* done parsing nested ResultSet */
        getPayloadInternal()->setResultSet(std::dynamic_pointer_cast<ResultSet>(resultSetParser_->getPayload()));
        resultSetParser_.reset();
    }
}

void MAMFinParser::handleCharacterData(const std::string& data) {
    if (resultSetParser_) {
        resultSetParser_->handleCharacterData(data);
    }
}
