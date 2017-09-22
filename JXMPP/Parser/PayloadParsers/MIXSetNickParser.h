#ifndef JXMPP_MIXSETNICKPARSER_H
#define JXMPP_MIXSETNICKPARSER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXSetNick.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>

namespace JXMPP {
    class JXMPP_API MIXSetNickParser : public GenericPayloadTreeParser<MIXSetNick> {
        public:
            MIXSetNickParser() {}
            virtual void handleTree(ParserElement::ref root) override;
    };
}

#endif // JXMPP_MIXSETNICKPARSER_H
