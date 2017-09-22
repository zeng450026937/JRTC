#ifndef JXMPP_MIXPAYLOADPARSER_H
#define JXMPP_MIXPAYLOADPARSER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXPayload.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>

namespace JXMPP {
    class JXMPP_API MIXPayloadParser : public GenericPayloadTreeParser<MIXPayload> {
        public:
            MIXPayloadParser() {}
            virtual void handleTree(ParserElement::ref root) override;
    };
}

#endif // JXMPP_MIXPAYLOADPARSER_H
