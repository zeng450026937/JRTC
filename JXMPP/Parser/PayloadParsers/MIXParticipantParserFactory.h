#ifndef JXMPP_MIXPARTICIPANTPARSERFACTORY_H
#define JXMPP_MIXPARTICIPANTPARSERFACTORY_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXParticipantParser.h>

namespace JXMPP {
    class JXMPP_API MIXParticipantParserFactory : public PayloadParserFactory {
        public:
            MIXParticipantParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return element == "participant" && ns == "urn:xmpp:mix:0";
            }

            virtual PayloadParser* createPayloadParser() {
                return new MIXParticipantParser();
            }
    };
}

#endif // JXMPP_MIXPARTICIPANTPARSERFACTORY_H
