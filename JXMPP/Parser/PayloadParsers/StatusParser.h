#ifndef JXMPP_STATUSPARSER_H
#define JXMPP_STATUSPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Status.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API StatusParser : public GenericPayloadParser<Status> {
        public:
            StatusParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
            std::string text_;
    };
}

#endif // JXMPP_STATUSPARSER_H
