#ifndef JXMPP_PUBSUBEVENTITEMPARSER_H
#define JXMPP_PUBSUBEVENTITEMPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventItem.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubEventItemParser : public GenericPayloadParser<PubSubEventItem> {
        public:
            PubSubEventItemParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubEventItemParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            PayloadParserFactoryCollection* parsers;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBEVENTITEMPARSER_H
