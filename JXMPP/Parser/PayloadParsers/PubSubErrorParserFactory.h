#ifndef JXMPP_PUBSUBERRORPARSERFACTORY_H
#define JXMPP_PUBSUBERRORPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/PubSubErrorParser.h>

namespace JXMPP {
    class JXMPP_API PubSubErrorParserFactory : public PayloadParserFactory {
        public:
            PubSubErrorParserFactory() {
            }
            ~PubSubErrorParserFactory();

            virtual bool canParse(const std::string&, const std::string& ns, const AttributeMap&) const {
                return ns == "http://jabber.org/protocol/pubsub#errors";
            }

            virtual PayloadParser* createPayloadParser() {
                return new PubSubErrorParser();
            }
    };
}

#endif // JXMPP_PUBSUBERRORPARSERFACTORY_H
