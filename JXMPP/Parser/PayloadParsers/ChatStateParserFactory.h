#ifndef JXMPP_CHATSTATEPARSERFACTORY_H
#define JXMPP_CHATSTATEPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>
#include <JXMPP/Parser/PayloadParsers/ChatStateParser.h>

namespace JXMPP {
    class JXMPP_API ChatStateParserFactory : public PayloadParserFactory {
        public:
            ChatStateParserFactory() {
            }

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return ns == "http://jabber.org/protocol/chatstates" &&
                    (element == "active" || element == "composing"
                     || element == "paused" || element == "inactive" || element == "gone");
            }

            virtual PayloadParser* createPayloadParser() {
                return new ChatStateParser();
            }

    };
}

#endif // JXMPP_CHATSTATEPARSERFACTORY_H
