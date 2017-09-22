#ifndef JXMPP_PUBSUBOPTIONSPARSER_H
#define JXMPP_PUBSUBOPTIONSPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOptions.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubOptionsParser : public GenericPayloadParser<PubSubOptions> {
        public:
            PubSubOptionsParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubOptionsParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBOPTIONSPARSER_H
