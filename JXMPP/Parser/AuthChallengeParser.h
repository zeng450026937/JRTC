#ifndef JXMPP_AUTHCHALLENGEPARSER_H
#define JXMPP_AUTHCHALLENGEPARSER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthChallenge.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API AuthChallengeParser : public GenericElementParser<AuthChallenge> {
        public:
            AuthChallengeParser();

            virtual void handleStartElement(const std::string&, const std::string& ns, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string& ns);
            virtual void handleCharacterData(const std::string&);

        private:
            int depth;
            std::string text;
    };
}

#endif // JXMPP_AUTHCHALLENGEPARSER_H
