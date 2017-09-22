#ifndef JXMPP_MUCINVITATIONPAYLOADPARSER_H
#define JXMPP_MUCINVITATIONPAYLOADPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCInvitationPayload.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>

namespace JXMPP {
    class JXMPP_API MUCInvitationPayloadParser : public GenericPayloadTreeParser<MUCInvitationPayload> {
        public:
            virtual void handleTree(ParserElement::ref root);
    };
}

#endif // JXMPP_MUCINVITATIONPAYLOADPARSER_H
