#include <JXMPP/Parser/PayloadParsers/DiscoItemsParser.h>

namespace JXMPP {

DiscoItemsParser::DiscoItemsParser() : level_(TopLevel) {
}

void DiscoItemsParser::handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) {
    if (level_ == PayloadLevel) {
        if (element == "item") {
            getPayloadInternal()->addItem(DiscoItems::Item(attributes.getAttribute("name"), JID(attributes.getAttribute("jid")), attributes.getAttribute("node")));
        }
    }
    else if (level_ == TopLevel) {
        if (element == "query") {
            getPayloadInternal()->setNode(attributes.getAttribute("node"));
        }
    }
    ++level_;
}

void DiscoItemsParser::handleEndElement(const std::string&, const std::string&) {
    --level_;
}

void DiscoItemsParser::handleCharacterData(const std::string&) {
}

}
