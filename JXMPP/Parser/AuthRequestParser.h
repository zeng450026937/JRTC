#ifndef JXMPP_AUTHREQUESTPARSER_H
#define JXMPP_AUTHREQUESTPARSER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthRequest.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API AuthRequestParser : public GenericElementParser<AuthRequest> {
        public:
            AuthRequestParser();

            virtual void handleStartElement(const std::string&, const std::string& ns, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string& ns);
            virtual void handleCharacterData(const std::string&);

        private:
            std::string text_;
            int depth_;
    };
}

#endif // JXMPP_AUTHREQUESTPARSER_H
