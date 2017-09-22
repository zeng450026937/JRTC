#ifndef JXMPP_USERTUNEPARSER_H
#define JXMPP_USERTUNEPARSER_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/UserTune.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API UserTuneParser : public GenericPayloadParser<UserTune> {
        public:
            UserTuneParser();
            virtual ~UserTuneParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            std::string currentText;
    };
}

#endif // JXMPP_USERTUNEPARSER_H
