#ifndef JXMPP_MUCDESTROYPAYLOADPARSER_H
#define JXMPP_MUCDESTROYPAYLOADPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCDestroyPayload.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>

namespace JXMPP {
    class JXMPP_API MUCDestroyPayloadParser : public GenericPayloadTreeParser<MUCDestroyPayload> {
        public:
            virtual void handleTree(ParserElement::ref root);
    };
}

#endif // JXMPP_MUCDESTROYPAYLOADPARSER_H
