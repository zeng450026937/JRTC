#ifndef JXMPP_PUBSUBEVENTPARSER_H
#define JXMPP_PUBSUBEVENTPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEvent.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubEventParser : public GenericPayloadParser<PubSubEvent> {
        public:
            PubSubEventParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubEventParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            PayloadParserFactoryCollection* parsers;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBEVENTPARSER_H
