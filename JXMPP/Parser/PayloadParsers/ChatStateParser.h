#ifndef JXMPP_CHATSTATEPARSER_H
#define JXMPP_CHATSTATEPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ChatState.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API ChatStateParser : public GenericPayloadParser<ChatState> {
        public:
            ChatStateParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
    };
}

#endif // JXMPP_CHATSTATEPARSER_H
