#ifndef JXMPP_MUCUSERPAYLOADPARSER_H
#define JXMPP_MUCUSERPAYLOADPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCUserPayload.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>
#include <JXMPP/Parser/PayloadParsers/MUCItemParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class JXMPP_API MUCUserPayloadParser : public GenericPayloadTreeParser<MUCUserPayload> {
        public:
            MUCUserPayloadParser(PayloadParserFactoryCollection* collection) : factories(collection) {}
            virtual void handleTree(ParserElement::ref root);
        private:
            PayloadParserFactoryCollection* factories;
    };
}

#endif // JXMPP_MUCUSERPAYLOADPARSER_H
