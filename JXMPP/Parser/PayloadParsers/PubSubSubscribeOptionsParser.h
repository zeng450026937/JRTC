#ifndef JXMPP_PUBSUBSUBSCRIBEOPTIONSPARSER_H
#define JXMPP_PUBSUBSUBSCRIBEOPTIONSPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubSubscribeOptions.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubSubscribeOptionsParser : public GenericPayloadParser<PubSubSubscribeOptions> {
        public:
            PubSubSubscribeOptionsParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubSubscribeOptionsParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIBEOPTIONSPARSER_H
