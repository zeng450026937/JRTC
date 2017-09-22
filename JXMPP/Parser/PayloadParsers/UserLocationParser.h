#ifndef JXMPP_USERLOCATIONPARSER_H
#define JXMPP_USERLOCATIONPARSER_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/UserLocation.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API UserLocationParser : public GenericPayloadParser<UserLocation> {
        public:
            UserLocationParser();
            virtual ~UserLocationParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::string currentText;
    };
}

#endif // JXMPP_USERLOCATIONPARSER_H
