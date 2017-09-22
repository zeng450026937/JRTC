#ifndef JXMPP_PUBSUBOWNERPUBSUBPARSER_H
#define JXMPP_PUBSUBOWNERPUBSUBPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerPubSub.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubOwnerPubSubParser : public GenericPayloadParser<PubSubOwnerPubSub> {
        public:
            PubSubOwnerPubSubParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubOwnerPubSubParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            PayloadParserFactoryCollection* parsers;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBOWNERPUBSUBPARSER_H
