#ifndef JXMPP_TREEREPARSER_H
#define JXMPP_TREEREPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>
#include <JXMPP/Parser/PayloadParsers/MUCItemParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class JXMPP_API TreeReparser {
        public:
            static std::shared_ptr<Payload> parseTree(ParserElement::ref root, PayloadParserFactoryCollection* collection);

    };
}

#endif // JXMPP_TREEREPARSER_H
