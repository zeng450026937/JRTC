#ifndef JXMPP_NICKNAMEPARSER_H
#define JXMPP_NICKNAMEPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Nickname.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API NicknameParser : public GenericPayloadParser<Nickname> {
        public:
            NicknameParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level;
            std::string text;
    };
}

#endif // JXMPP_NICKNAMEPARSER_H
