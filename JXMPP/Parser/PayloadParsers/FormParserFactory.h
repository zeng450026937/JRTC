#ifndef JXMPP_FORMPARSERFACTORY_H
#define JXMPP_FORMPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/FormParser.h>

namespace JXMPP {
    class JXMPP_API FormParserFactory : public PayloadParserFactory {
        public:
            FormParserFactory() {
            }

            virtual bool canParse(const std::string& /*element*/, const std::string& ns, const AttributeMap&) const {
                return ns == "jabber:x:data";
            }

            virtual PayloadParser* createPayloadParser() {
                return new FormParser();
            }

    };
}

#endif // JXMPP_FORMPARSERFACTORY_H
