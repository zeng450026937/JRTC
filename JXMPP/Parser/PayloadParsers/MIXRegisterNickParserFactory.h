#ifndef JXMPP_MIXREGISTERNICKPARSERFACTORY_H
#define JXMPP_MIXREGISTERNICKPARSERFACTORY_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MIXRegisterNickParser.h>

namespace JXMPP {
    class JXMPP_API MIXRegisterNickParserFactory : public PayloadParserFactory {
        public:
            MIXRegisterNickParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const override {
                return element == "register" && ns == "urn:xmpp:mix:0";
            }

            virtual PayloadParser* createPayloadParser() override {
                return new MIXRegisterNickParser();
            }
    };
}

#endif // JXMPP_MIXREGISTERNICKPARSERFACTORY_H
