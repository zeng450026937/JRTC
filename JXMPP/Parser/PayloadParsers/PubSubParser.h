#ifndef JXMPP_PUBSUBPARSER_H
#define JXMPP_PUBSUBPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSub.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;
    class PubSubOptions;
    class PubSubConfigure;

    class JXMPP_API PubSubParser : public GenericPayloadParser<PubSub> {
        public:
            PubSubParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            PayloadParserFactoryCollection* parsers;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
            std::shared_ptr<PubSubConfigure> configurePayload;
            std::shared_ptr<PubSubOptions> optionsPayload;
    };
}

#endif // JXMPP_PUBSUBPARSER_H
