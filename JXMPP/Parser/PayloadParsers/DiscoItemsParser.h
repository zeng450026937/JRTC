#ifndef JXMPP_DISCOITEMSPARSER_H
#define JXMPP_DISCOITEMSPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoItems.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API DiscoItemsParser : public GenericPayloadParser<DiscoItems> {
        public:
            DiscoItemsParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };
            int level_;
    };
}

#endif // JXMPP_DISCOITEMSPARSER_H
