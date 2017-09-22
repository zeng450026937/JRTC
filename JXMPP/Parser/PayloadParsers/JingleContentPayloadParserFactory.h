#ifndef JXMPP_JINGLECONTENTPAYLOADPARSERFACTORY_H
#define JXMPP_JINGLECONTENTPAYLOADPARSERFACTORY_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/JingleContentPayloadParser.h>

namespace JXMPP {

    class PayloadParserFactoryCollection;

    class JXMPP_API JingleContentPayloadParserFactory : public PayloadParserFactory {
        public:
            JingleContentPayloadParserFactory(PayloadParserFactoryCollection* factories) : factories(factories) {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return element == "content" && ns == "urn:xmpp:jingle:1";
            }

            virtual PayloadParser* createPayloadParser() {
                return new JingleContentPayloadParser(factories);
            }

        private:
            PayloadParserFactoryCollection* factories;

    };
}

#endif // JXMPP_JINGLECONTENTPAYLOADPARSERFACTORY_H
