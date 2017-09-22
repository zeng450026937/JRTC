#ifndef JXMPP_MUCOWNERPAYLOADPARSERFACTORY_H
#define JXMPP_MUCOWNERPAYLOADPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MUCOwnerPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;

    class JXMPP_API MUCOwnerPayloadParserFactory : public PayloadParserFactory {
        public:
            MUCOwnerPayloadParserFactory(PayloadParserFactoryCollection* factories) : factories(factories) {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return element == "query" && ns == "http://jabber.org/protocol/muc#owner";
            }

            virtual PayloadParser* createPayloadParser() {
                return new MUCOwnerPayloadParser(factories);
            }

        private:
            PayloadParserFactoryCollection* factories;

    };
}

#endif // JXMPP_MUCOWNERPAYLOADPARSERFACTORY_H
