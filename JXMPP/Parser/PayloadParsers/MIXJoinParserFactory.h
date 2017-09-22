#ifndef JXMPP_MIXJOINPARSERFACTORY_H
#define JXMPP_MIXJOINPARSERFACTORY_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXJoinParser.h>

namespace JXMPP {
    class JXMPP_API MIXJoinParserFactory : public PayloadParserFactory {
        public:
            MIXJoinParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return element == "join" && ns == "urn:xmpp:mix:0";
            }

            virtual PayloadParser* createPayloadParser() {
                return new MIXJoinParser();
            }
    };
}

#endif // JXMPP_MIXJOINPARSERFACTORY_H
