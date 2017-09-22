#include <JXMPP/Parser/Tree/TreeReparser.h>

#include <deque>
#include <utility>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Elements/MUCOccupant.h>
#include <JXMPP/Parser/PayloadParser.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParserFactoryCollection.h>

namespace JXMPP {

typedef std::pair<ParserElement::ref, bool> ElementState;

std::shared_ptr<Payload> TreeReparser::parseTree(ParserElement::ref root, PayloadParserFactoryCollection* collection) {
    PayloadParser* parser = collection->getPayloadParserFactory(root->getName(), root->getNamespace(), root->getAttributes())->createPayloadParser();
    std::deque<ElementState > stack;
    stack.push_back(ElementState(root, true));
    while (!stack.empty()) {
        ElementState current = stack.back();
        stack.pop_back();
        if (current.second) {
            stack.push_back(ElementState(current.first, false));
            parser->handleStartElement(current.first->getName(), current.first->getNamespace(), current.first->getAttributes());
            for (const auto& child : current.first->getAllChildren()) {
                stack.push_back(ElementState(child, true));
            }
        } else {
            parser->handleCharacterData(current.first->getText());
            parser->handleEndElement(current.first->getName(), current.first->getNamespace());
        }

    }

    std::shared_ptr<Payload> payload = parser->getPayload();
    delete parser;
    return payload;
}

}
