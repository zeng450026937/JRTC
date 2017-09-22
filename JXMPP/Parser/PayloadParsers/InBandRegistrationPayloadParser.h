#ifndef JXMPP_INBANDREGISTRATIONPAYLOADPARSER_H
#define JXMPP_INBANDREGISTRATIONPAYLOADPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/InBandRegistrationPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class FormParserFactory;
    class FormParser;

    class JXMPP_API InBandRegistrationPayloadParser : public GenericPayloadParser<InBandRegistrationPayload> {
        public:
            InBandRegistrationPayloadParser();
            ~InBandRegistrationPayloadParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };
            int level;
            FormParserFactory* formParserFactory;
            FormParser* formParser;
            std::string currentText;
    };
}

#endif // JXMPP_INBANDREGISTRATIONPAYLOADPARSER_H
