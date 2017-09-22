#ifndef JXMPP_PRESENCEPARSER_H
#define JXMPP_PRESENCEPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/Parser/GenericStanzaParser.h>

namespace JXMPP {
    class JXMPP_API PresenceParser : public GenericStanzaParser<Presence> {
        public:
            PresenceParser(PayloadParserFactoryCollection* factories);

        private:
            virtual void handleStanzaAttributes(const AttributeMap&);
    };
}

#endif // JXMPP_PRESENCEPARSER_H
