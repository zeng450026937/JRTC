#ifndef JXMPP_SECURITYLABELSCATALOGPARSER_H
#define JXMPP_SECURITYLABELSCATALOGPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SecurityLabelsCatalog.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class SecurityLabelParserFactory;
    class SecurityLabelParser;

    class JXMPP_API SecurityLabelsCatalogParser : public GenericPayloadParser<SecurityLabelsCatalog> {
        public:
            SecurityLabelsCatalogParser();
            ~SecurityLabelsCatalogParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1,
                ItemLevel = 2,
                LabelLevel = 3
            };
            int level_;
            SecurityLabelParserFactory* labelParserFactory_;
            SecurityLabelParser* labelParser_;
            std::shared_ptr<SecurityLabelsCatalog::Item> currentItem_;
    };
}

#endif // JXMPP_SECURITYLABELSCATALOGPARSER_H
