#ifndef JXMPP_COMMANDPARSER_H
#define JXMPP_COMMANDPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Command.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class FormParserFactory;
    class FormParser;

    class JXMPP_API CommandParser : public GenericPayloadParser<Command> {
        public:
            CommandParser();
            ~CommandParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            static boost::optional<Command::Action> parseAction(const std::string& action);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1,
                FormOrNoteOrActionsLevel = 2,
                ActionsActionLevel = 3
            };
            int level_;
            bool inNote_;
            bool inActions_;
            Command::Note::Type noteType_;
            FormParserFactory* formParserFactory_;
            FormParser* formParser_;
            std::string currentText_;
    };
}

#endif // JXMPP_COMMANDPARSER_H
