#ifndef JXMPP_PRIORITYPARSER_H
#define JXMPP_PRIORITYPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Priority.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API PriorityParser : public GenericPayloadParser<Priority> {
        public:
            PriorityParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
            std::string text_;
    };
}

#endif // JXMPP_PRIORITYPARSER_H
