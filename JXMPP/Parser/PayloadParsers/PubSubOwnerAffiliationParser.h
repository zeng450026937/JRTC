#ifndef JXMPP_PUBSUBOWNERAFFILIATIONPARSER_H
#define JXMPP_PUBSUBOWNERAFFILIATIONPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerAffiliation.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubOwnerAffiliationParser : public GenericPayloadParser<PubSubOwnerAffiliation> {
        public:
            PubSubOwnerAffiliationParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubOwnerAffiliationParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBOWNERAFFILIATIONPARSER_H
