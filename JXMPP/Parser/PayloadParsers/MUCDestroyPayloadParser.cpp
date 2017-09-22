#include <JXMPP/Parser/PayloadParsers/MUCDestroyPayloadParser.h>

namespace JXMPP {

void MUCDestroyPayloadParser::handleTree(ParserElement::ref root) {
    std::string ns = root->getNamespace();
    std::string jid = root->getAttributes().getAttribute("jid");
    if (!jid.empty()) {
        getPayloadInternal()->setNewVenue(JID(jid));
    }
    getPayloadInternal()->setReason(root->getChild("reason", ns)->getText());
}

}
