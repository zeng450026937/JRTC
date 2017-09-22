#ifndef JXMPP_COMPONENTHANDSHAKEPARSER_H
#define JXMPP_COMPONENTHANDSHAKEPARSER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ComponentHandshake.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API ComponentHandshakeParser : public GenericElementParser<ComponentHandshake> {
        public:
            ComponentHandshakeParser();

            virtual void handleStartElement(const std::string&, const std::string& ns, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string& ns);
            virtual void handleCharacterData(const std::string&);

        private:
            int depth;
            std::string text;
    };
}

#endif // JXMPP_COMPONENTHANDSHAKEPARSER_H
