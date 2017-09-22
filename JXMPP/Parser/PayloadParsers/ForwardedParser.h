#ifndef JXMPP_FORWARDEDPARSER_H
#define JXMPP_FORWARDEDPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Forwarded.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class StanzaParser;
    class DelayParser;

    class JXMPP_API ForwardedParser : public GenericPayloadParser<Forwarded> {
        public:
            ForwardedParser(PayloadParserFactoryCollection* factories);

            virtual void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };

        private:
            PayloadParserFactoryCollection* factories_;
            std::shared_ptr<StanzaParser> childParser_;
            std::shared_ptr<DelayParser> delayParser_;
            int level_;
    };
}

#endif // JXMPP_FORWARDEDPARSER_H
