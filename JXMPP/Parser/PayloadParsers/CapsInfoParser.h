#ifndef JXMPP_CAPSINFOPARSER_H
#define JXMPP_CAPSINFOPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CapsInfo.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API CapsInfoParser : public GenericPayloadParser<CapsInfo> {
        public:
            CapsInfoParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level;
    };
}

#endif // JXMPP_CAPSINFOPARSER_H
