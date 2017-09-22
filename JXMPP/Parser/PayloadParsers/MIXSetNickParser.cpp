/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Parser/PayloadParsers/MIXSetNickParser.h>

namespace JXMPP {

void MIXSetNickParser::handleTree(ParserElement::ref root) {
    for (const auto& child : root->getAllChildren()) {
        if (child->getName() == "nick" && child->getNamespace() == root->getNamespace()) {
            getPayloadInternal()->setNick(child->getText());
        }
    }
}

}
