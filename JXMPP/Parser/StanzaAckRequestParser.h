#ifndef JXMPP_STANZAACKREQUESTPARSER_H
#define JXMPP_STANZAACKREQUESTPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StanzaAckRequest.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StanzaAckRequestParser : public GenericElementParser<StanzaAckRequest> {
        public:
            StanzaAckRequestParser() : GenericElementParser<StanzaAckRequest>() {}
    };
}

#endif // JXMPP_STANZAACKREQUESTPARSER_H
