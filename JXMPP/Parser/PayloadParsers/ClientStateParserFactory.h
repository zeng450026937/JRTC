#ifndef JXMPP_CLIENTSTATEPARSERFACTORY_H
#define JXMPP_CLIENTSTATEPARSERFACTORY_H

/*
 * Copyright (c) 2017 Tarun Gupta.
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/ClientStateParser.h>

namespace JXMPP {
    class JXMPP_API ClientStateParserFactory : public PayloadParserFactory {
        public:
            ClientStateParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return ns == "urn:xmpp:csi:0" &&
                    (element == "active" || element == "inactive");
            }

            virtual PayloadParser* createPayloadParser() {
                return new ClientStateParser();
            }

    };
}

#endif // JXMPP_CLIENTSTATEPARSERFACTORY_H
