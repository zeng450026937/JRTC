#ifndef JXMPP_PUBSUBEVENTDELETEPARSER_H
#define JXMPP_PUBSUBEVENTDELETEPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventDelete.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubEventDeleteParser : public GenericPayloadParser<PubSubEventDelete> {
        public:
            PubSubEventDeleteParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubEventDeleteParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            PayloadParserFactoryCollection* parsers;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBEVENTDELETEPARSER_H
