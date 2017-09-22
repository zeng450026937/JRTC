#ifndef JXMPP_PUBSUBOWNERSUBSCRIPTIONPARSER_H
#define JXMPP_PUBSUBOWNERSUBSCRIPTIONPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerSubscription.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubOwnerSubscriptionParser : public GenericPayloadParser<PubSubOwnerSubscription> {
        public:
            PubSubOwnerSubscriptionParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubOwnerSubscriptionParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBOWNERSUBSCRIPTIONPARSER_H
