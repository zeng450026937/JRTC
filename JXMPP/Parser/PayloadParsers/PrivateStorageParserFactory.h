#ifndef JXMPP_PRIVATESTORAGEPARSERFACTORY_H
#define JXMPP_PRIVATESTORAGEPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/PrivateStorageParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;

    class JXMPP_API PrivateStorageParserFactory : public PayloadParserFactory {
        public:
            PrivateStorageParserFactory(PayloadParserFactoryCollection* factories) : factories(factories) {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return element == "query" && ns == "jabber:iq:private";
            }

            virtual PayloadParser* createPayloadParser() {
                return new PrivateStorageParser(factories);
            }

        private:
            PayloadParserFactoryCollection* factories;

    };
}

#endif // JXMPP_PRIVATESTORAGEPARSERFACTORY_H
