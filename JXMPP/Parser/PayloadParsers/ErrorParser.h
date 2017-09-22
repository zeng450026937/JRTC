#ifndef JXMPP_ERRORPARSER_H
#define JXMPP_ERRORPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class JXMPP_API ErrorParser : public GenericPayloadParser<ErrorPayload> {
        public:
            ErrorParser(PayloadParserFactoryCollection* factories);

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };
            PayloadParserFactoryCollection* factories;
            int level_;
            std::string currentText_;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_ERRORPARSER_H
