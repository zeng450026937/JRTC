#include <JXMPP/Parser/PayloadParsers/MUCUserPayloadParser.h>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Elements/MUCOccupant.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>
#include <JXMPP/Parser/Tree/TreeReparser.h>

namespace JXMPP {

void MUCUserPayloadParser::handleTree(ParserElement::ref root) {
    for (const auto& child : root->getAllChildren()) {
        if (child->getName() == "item" && child->getNamespace() == root->getNamespace()) {
            MUCItem item = MUCItemParser::itemFromTree(child);
            getPayloadInternal()->addItem(item);
        }
        else if (child->getName() == "password" && child->getNamespace() == root->getNamespace()) {
            getPayloadInternal()->setPassword(child->getText());
        }
        else if (child->getName() == "invite" && child->getNamespace() == root->getNamespace()) {
            MUCUserPayload::Invite invite;
            std::string to = child->getAttributes().getAttribute("to");
            if (!to.empty()) {
                invite.to = to;
            }
            std::string from = child->getAttributes().getAttribute("from");
            if (!from.empty()) {
                invite.from = from;
            }
            ParserElement::ref reason = child->getChild("reason", root->getNamespace());
            if (reason) {
                invite.reason = reason->getText();
            }
            getPayloadInternal()->setInvite(invite);
        }
        else if (child->getName() == "status" && child->getNamespace() == root->getNamespace()) {
            MUCUserPayload::StatusCode status;
            try {
                status.code = boost::lexical_cast<int>(child->getAttributes().getAttribute("code").c_str());
                getPayloadInternal()->addStatusCode(status);
            } catch (boost::bad_lexical_cast&) {
            }
        }
        else {
            getPayloadInternal()->setPayload(TreeReparser::parseTree(child, factories));
        }
    }
}

}
