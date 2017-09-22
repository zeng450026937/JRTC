#ifndef JXMPP_SECURITYLABELPARSER_H
#define JXMPP_SECURITYLABELPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SecurityLabel.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class SerializingParser;

    class JXMPP_API SecurityLabelParser : public GenericPayloadParser<SecurityLabel> {
        public:
            SecurityLabelParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);
            std::shared_ptr<SecurityLabel> getLabelPayload() const;
        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1,
                DisplayMarkingOrLabelLevel = 2,
                SecurityLabelLevel = 3
            };
            int level_;
            SerializingParser* labelParser_;
            std::string currentText_;
    };
}

#endif // JXMPP_SECURITYLABELPARSER_H
