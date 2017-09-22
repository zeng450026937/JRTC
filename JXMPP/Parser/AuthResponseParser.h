#ifndef JXMPP_AUTHRESPONSEPARSER_H
#define JXMPP_AUTHRESPONSEPARSER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthResponse.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API AuthResponseParser : public GenericElementParser<AuthResponse> {
        public:
            AuthResponseParser();

            virtual void handleStartElement(const std::string&, const std::string& ns, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string& ns);
            virtual void handleCharacterData(const std::string&);

        private:
            int depth;
            std::string text;
    };
}

#endif // JXMPP_AUTHRESPONSEPARSER_H
