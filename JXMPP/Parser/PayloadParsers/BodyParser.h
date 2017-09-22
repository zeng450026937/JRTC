#ifndef JXMPP_BODYPARSER_H
#define JXMPP_BODYPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Body.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API BodyParser : public GenericPayloadParser<Body> {
        public:
            BodyParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
            std::string text_;
    };
}

#endif // JXMPP_BODYPARSER_H
