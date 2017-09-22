#ifndef JXMPP_ERRORPARSERFACTORY_H
#define JXMPP_ERRORPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/ErrorParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;

    class JXMPP_API ErrorParserFactory : public PayloadParserFactory {
        public:
            ErrorParserFactory(PayloadParserFactoryCollection* factories) : factories(factories) {
            }

            virtual bool canParse(const std::string& element, const std::string& /*ns*/, const AttributeMap&) const {
                return element == "error";
            }

            virtual PayloadParser* createPayloadParser() {
                return new ErrorParser(factories);
            }

        private:
            PayloadParserFactoryCollection* factories;

    };
}

#endif // JXMPP_ERRORPARSERFACTORY_H
