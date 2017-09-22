#ifndef JXMPP_PUBSUBEVENTCONFIGURATIONPARSER_H
#define JXMPP_PUBSUBEVENTCONFIGURATIONPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventConfiguration.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubEventConfigurationParser : public GenericPayloadParser<PubSubEventConfiguration> {
        public:
            PubSubEventConfigurationParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubEventConfigurationParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBEVENTCONFIGURATIONPARSER_H
