#ifndef JXMPP_STARTSESSIONPARSER_H
#define JXMPP_STARTSESSIONPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StartSession.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API StartSessionParser : public GenericPayloadParser<StartSession> {
        public:
            StartSessionParser() {}

            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&) {}
            virtual void handleEndElement(const std::string&, const std::string&) {}
            virtual void handleCharacterData(const std::string&) {}
    };
}

#endif // JXMPP_STARTSESSIONPARSER_H
