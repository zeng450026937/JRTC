#ifndef JXMPP_PUBSUBOWNERPURGEPARSER_H
#define JXMPP_PUBSUBOWNERPURGEPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubOwnerPurge.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubOwnerPurgeParser : public GenericPayloadParser<PubSubOwnerPurge> {
        public:
            PubSubOwnerPurgeParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubOwnerPurgeParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBOWNERPURGEPARSER_H
