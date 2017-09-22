#ifndef JXMPP_MUCUSERPAYLOADPARSERFACTORY_H
#define JXMPP_MUCUSERPAYLOADPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/MUCUserPayloadParser.h>

namespace JXMPP {
    class JXMPP_API MUCUserPayloadParserFactory : public PayloadParserFactory {
        public:
            MUCUserPayloadParserFactory(PayloadParserFactoryCollection* factories) : factories(factories) {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return element == "x" && ns == "http://jabber.org/protocol/muc#user";
            }

            virtual PayloadParser* createPayloadParser() {
                return new MUCUserPayloadParser(factories);
            }

        private:
            PayloadParserFactoryCollection* factories;
    };
}

#endif // JXMPP_MUCUSERPAYLOADPARSERFACTORY_H
