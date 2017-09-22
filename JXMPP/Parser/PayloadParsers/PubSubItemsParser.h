#ifndef JXMPP_PUBSUBITEMSPARSER_H
#define JXMPP_PUBSUBITEMSPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubItems.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubItemsParser : public GenericPayloadParser<PubSubItems> {
        public:
            PubSubItemsParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubItemsParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            PayloadParserFactoryCollection* parsers;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBITEMSPARSER_H
