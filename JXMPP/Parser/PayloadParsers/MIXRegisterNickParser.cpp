/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */

#include <JXMPP/Parser/PayloadParsers/MIXRegisterNickParser.h>

namespace JXMPP {

void MIXRegisterNickParser::handleTree(ParserElement::ref root) {
    for (const auto& child : root->getAllChildren()) {
        if (child->getName() == "nick" && child->getNamespace() == root->getNamespace()) {
            getPayloadInternal()->setNick(child->getText());
        }
    }
}

}
