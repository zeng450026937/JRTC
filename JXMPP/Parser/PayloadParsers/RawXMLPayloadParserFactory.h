#ifndef JXMPP_RAWXMLPAYLOADPARSERFACTORY_H
#define JXMPP_RAWXMLPAYLOADPARSERFACTORY_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/RawXMLPayloadParser.h>

namespace JXMPP {
    class JXMPP_API RawXMLPayloadParserFactory : public PayloadParserFactory {
        public:
            RawXMLPayloadParserFactory() {}

            virtual bool canParse(const std::string&, const std::string&, const AttributeMap&) const {
                return true;
            }

            virtual PayloadParser* createPayloadParser() {
                return new RawXMLPayloadParser();
            }
    };
}

#endif // JXMPP_RAWXMLPAYLOADPARSERFACTORY_H
