#ifndef JXMPP_MIXPARTICIPANTPARSER_H
#define JXMPP_MIXPARTICIPANTPARSER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXParticipant.h>
#include <JXMPP/Parser/GenericPayloadTreeParser.h>

namespace JXMPP {
    class JXMPP_API MIXParticipantParser : public GenericPayloadTreeParser<MIXParticipant> {
        public:
            MIXParticipantParser() {}
            virtual void handleTree(ParserElement::ref root);
    };
}

#endif // JXMPP_MIXPARTICIPANTPARSER_H
