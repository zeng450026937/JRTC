#ifndef JXMPP_PUBSUBSUBSCRIPTIONSPARSER_H
#define JXMPP_PUBSUBSUBSCRIPTIONSPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubSubscriptions.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubSubscriptionsParser : public GenericPayloadParser<PubSubSubscriptions> {
        public:
            PubSubSubscriptionsParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubSubscriptionsParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            PayloadParserFactoryCollection* parsers;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBSUBSCRIPTIONSPARSER_H
