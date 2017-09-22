#ifndef JXMPP_MAMRESULTPARSER_H
#define JXMPP_MAMRESULTPARSER_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MAMResult.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;
    class ForwardedParser;

    class JXMPP_API MAMResultParser : public GenericPayloadParser<MAMResult> {
        public:
            MAMResultParser(PayloadParserFactoryCollection* factories);

            virtual void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };

        private:
            std::shared_ptr<ForwardedParser> payloadParser_;
            PayloadParserFactoryCollection* factories_;
            int level_;
    };
}

#endif // JXMPP_MAMRESULTPARSER_H
