#ifndef JXMPP_SEARCHPAYLOADPARSER_H
#define JXMPP_SEARCHPAYLOADPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SearchPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class FormParserFactory;
    class FormParser;

    class JXMPP_API SearchPayloadParser : public GenericPayloadParser<SearchPayload> {
        public:
            SearchPayloadParser();
            ~SearchPayloadParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1,
                ItemLevel = 2
            };
            int level;
            FormParserFactory* formParserFactory;
            FormParser* formParser;
            std::string currentText;
            boost::optional<SearchPayload::Item> currentItem;
    };
}

#endif // JXMPP_SEARCHPAYLOADPARSER_H
