#ifndef JXMPP_PUBSUBOWNERDELETEPARSER_H
#define JXMPP_PUBSUBOWNERDELETEPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerDelete.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubOwnerDeleteParser : public GenericPayloadParser<PubSubOwnerDelete> {
        public:
            PubSubOwnerDeleteParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubOwnerDeleteParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            PayloadParserFactoryCollection* parsers;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBOWNERDELETEPARSER_H
