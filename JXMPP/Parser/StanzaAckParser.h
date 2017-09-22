#ifndef JXMPP_STANZAACKPARSER_H
#define JXMPP_STANZAACKPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StanzaAck.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StanzaAckParser : public GenericElementParser<StanzaAck> {
        public:
            StanzaAckParser();

            virtual void handleStartElement(const std::string&, const std::string& ns, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string& ns);

        private:
            int depth;
    };
}

#endif // JXMPP_STANZAACKPARSER_H
