#ifndef JXMPP_PUBSUBSUBSCRIBEPARSER_H
#define JXMPP_PUBSUBSUBSCRIBEPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubSubscribe.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubSubscribeParser : public GenericPayloadParser<PubSubSubscribe> {
        public:
            PubSubSubscribeParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubSubscribeParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIBEPARSER_H
