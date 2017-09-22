#ifndef JXMPP_MIXPAYLOADPARSERFACTORY_H
#define JXMPP_MIXPAYLOADPARSERFACTORY_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXPayloadParser.h>

namespace JXMPP {
    class JXMPP_API MIXPayloadParserFactory : public PayloadParserFactory {
        public:
            MIXPayloadParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const override {
                return element == "mix" && ns == "urn:xmpp:mix:0";
            }

            virtual PayloadParser* createPayloadParser() override {
                return new MIXPayloadParser();
            }
    };
}

#endif // JXMPP_MIXPAYLOADPARSERFACTORY_H
