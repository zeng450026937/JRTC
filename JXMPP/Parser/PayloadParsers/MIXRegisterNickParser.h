#ifndef JXMPP_MIXREGISTERNICKPARSER_H
#define JXMPP_MIXREGISTERNICKPARSER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXRegisterNick.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>

namespace JXMPP {
    class JXMPP_API MIXRegisterNickParser : public GenericPayloadTreeParser<MIXRegisterNick> {
        public:
            MIXRegisterNickParser() {}
            virtual void handleTree(ParserElement::ref root) override;
    };
}

#endif // JXMPP_MIXREGISTERNICKPARSER_H
