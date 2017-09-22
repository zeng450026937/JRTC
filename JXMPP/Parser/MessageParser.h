#ifndef JXMPP_MESSAGEPARSER_H
#define JXMPP_MESSAGEPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/Parser/GenericStanzaParser.h>

namespace JXMPP {
    class JXMPP_API MessageParser : public GenericStanzaParser<Message> {
        public:
            MessageParser(PayloadParserFactoryCollection* factories);

        private:
            virtual void handleStanzaAttributes(const AttributeMap&);
    };
}

#endif // JXMPP_MESSAGEPARSER_H
