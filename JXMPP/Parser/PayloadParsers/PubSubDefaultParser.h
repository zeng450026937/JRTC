#ifndef JXMPP_PUBSUBDEFAULTPARSER_H
#define JXMPP_PUBSUBDEFAULTPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubDefault.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubDefaultParser : public GenericPayloadParser<PubSubDefault> {
        public:
            PubSubDefaultParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubDefaultParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBDEFAULTPARSER_H
