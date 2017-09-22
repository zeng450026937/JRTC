#include <JXMPP/Parser/PayloadParsers/MUCAdminPayloadParser.h>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Elements/MUCOccupant.h>

namespace JXMPP {

void MUCAdminPayloadParser::handleTree(ParserElement::ref root) {
    for (const auto& itemElement : root->getChildren("item", "http://jabber.org/protocol/muc#admin")) {
        MUCItem item = MUCItemParser::itemFromTree(itemElement);
        getPayloadInternal()->addItem(item);
    }
}

}
