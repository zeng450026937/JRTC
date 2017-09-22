#include <JXMPP/Parser/PayloadParsers/ResultSetParser.h>

#include <boost/lexical_cast.hpp>
#include <boost/optional.hpp>

#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>

using namespace JXMPP;

ResultSetParser::ResultSetParser() : level_(TopLevel) {
}

void ResultSetParser::handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
    currentText_ = "";
    if (level_ == PayloadLevel) {
        if (element == "first" && ns == "http://jabber.org/protocol/rsm") {
            if (boost::optional<std::string> attributeValue = attributes.getAttributeValue("index")) {
                try {
                    getPayloadInternal()->setFirstIDIndex(boost::lexical_cast<int>(*attributeValue));
                } catch(boost::bad_lexical_cast&) {
                }
            }
        }
    }
    ++level_;
}

void ResultSetParser::handleEndElement(const std::string& element, const std::string&) {
    --level_;
    if (level_ == PayloadLevel) {
        if (element == "max") {
            try {
                getPayloadInternal()->setMaxItems(boost::lexical_cast<int>(currentText_));
            } catch(boost::bad_lexical_cast&) {
            }
        } else if (element == "count") {
            try {
                getPayloadInternal()->setCount(boost::lexical_cast<int>(currentText_));
            } catch(boost::bad_lexical_cast&) {
            }
        } else if (element == "index") {
            try {
                getPayloadInternal()->setIndex(boost::lexical_cast<int>(currentText_));
            } catch(boost::bad_lexical_cast&) {
            }
        } else if (element == "first") {
            getPayloadInternal()->setFirstID(currentText_);
        } else if (element == "last") {
            getPayloadInternal()->setLastID(currentText_);
        } else if (element == "before") {
            getPayloadInternal()->setBefore(currentText_);
        } else if (element == "after") {
            getPayloadInternal()->setAfter(currentText_);
        }
    }
}

void ResultSetParser::handleCharacterData(const std::string& data) {
    currentText_ += data;
}
