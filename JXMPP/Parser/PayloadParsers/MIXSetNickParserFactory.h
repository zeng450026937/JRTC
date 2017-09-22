#ifndef JXMPP_MIXSETNICKPARSERFACTORY_H
#define JXMPP_MIXSETNICKPARSERFACTORY_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXSetNickParser.h>

namespace JXMPP {
    class JXMPP_API MIXSetNickParserFactory : public PayloadParserFactory {
        public:
            MIXSetNickParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const override {
                return element == "setnick" && ns == "urn:xmpp:mix:0";
            }

            virtual PayloadParser* createPayloadParser() override {
                return new MIXSetNickParser();
            }
    };
}

#endif // JXMPP_MIXSETNICKPARSERFACTORY_H
