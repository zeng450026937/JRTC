#ifndef JXMPP_CARBONSRECEIVEDPARSER_H
#define JXMPP_CARBONSRECEIVEDPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsReceived.h>
#include <JXMPP/Parser/GenericPayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/ForwardedParser.h>

namespace JXMPP {
    class JXMPP_API CarbonsReceivedParser : public GenericPayloadParser<CarbonsReceived> {
        public:
            CarbonsReceivedParser(PayloadParserFactoryCollection* factories);
            virtual ~CarbonsReceivedParser();
            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap&);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string&);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };


        private:
            PayloadParserFactoryCollection* factories_;
            std::shared_ptr<ForwardedParser> forwardedParser_;
            int level_;
    };
}

#endif // JXMPP_CARBONSRECEIVEDPARSER_H
