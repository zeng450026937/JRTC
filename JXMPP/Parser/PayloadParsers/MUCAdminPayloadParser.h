#ifndef JXMPP_MUCADMINPAYLOADPARSER_H
#define JXMPP_MUCADMINPAYLOADPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCAdminPayload.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>
#include <JXMPP/Parser/PayloadParsers/MUCItemParser.h>

namespace JXMPP {
    class JXMPP_API MUCAdminPayloadParser : public GenericPayloadTreeParser<MUCAdminPayload> {
        public:
            virtual void handleTree(ParserElement::ref root);
    };
}

#endif // JXMPP_MUCADMINPAYLOADPARSER_H
