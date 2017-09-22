#ifndef JXMPP_ROSTERPARSER_H
#define JXMPP_ROSTERPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RosterPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class SerializingParser;

    class JXMPP_API RosterParser : public GenericPayloadParser<RosterPayload> {
        public:
            RosterParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1,
                ItemLevel = 2
            };
            int level_;
            bool inItem_;
            RosterItemPayload currentItem_;
            std::string currentText_;
            SerializingParser* unknownContentParser_;
    };
}

#endif // JXMPP_ROSTERPARSER_H
