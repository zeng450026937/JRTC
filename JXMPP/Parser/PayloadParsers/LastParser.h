#ifndef JXMPP_LASTPARSER_H
#define JXMPP_LASTPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Last.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API LastParser : public GenericPayloadParser<Last> {
        public:
            LastParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
    };
}

#endif // JXMPP_LASTPARSER_H
