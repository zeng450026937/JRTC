#ifndef JXMPP_PUBSUBEVENTDISASSOCIATEPARSER_H
#define JXMPP_PUBSUBEVENTDISASSOCIATEPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubEventDisassociate.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class PayloadParser;

    class JXMPP_API PubSubEventDisassociateParser : public GenericPayloadParser<PubSubEventDisassociate> {
        public:
            PubSubEventDisassociateParser(PayloadParserFactoryCollection* parsers);
            virtual ~PubSubEventDisassociateParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_PUBSUBEVENTDISASSOCIATEPARSER_H
