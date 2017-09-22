#ifndef JXMPP_JINGLEPARSERFACTORY_H
#define JXMPP_JINGLEPARSERFACTORY_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/JingleParser.h>

namespace JXMPP {

    class PayloadParserFactoryCollection;

    class JXMPP_API JingleParserFactory : public PayloadParserFactory {
        public:
            JingleParserFactory(PayloadParserFactoryCollection* factories) : factories(factories) {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return element == "jingle" && ns == "urn:xmpp:jingle:1";
            }

            virtual PayloadParser* createPayloadParser() {
                return new JingleParser(factories);
            }

        private:
            PayloadParserFactoryCollection* factories;

    };
}

#endif // JXMPP_JINGLEPARSERFACTORY_H
