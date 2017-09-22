#ifndef JXMPP_AUTHSUCCESSPARSER_H
#define JXMPP_AUTHSUCCESSPARSER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthSuccess.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API AuthSuccessParser : public GenericElementParser<AuthSuccess> {
        public:
            AuthSuccessParser();

            virtual void handleStartElement(const std::string&, const std::string& ns, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string& ns);
            virtual void handleCharacterData(const std::string&);

        private:
            int depth;
            std::string text;
    };
}

#endif // JXMPP_AUTHSUCCESSPARSER_H
