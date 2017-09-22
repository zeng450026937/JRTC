#ifndef JXMPP_DELAYPARSER_H
#define JXMPP_DELAYPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Delay.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API DelayParser : public GenericPayloadParser<Delay> {
        public:
            DelayParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
    };
}

#endif // JXMPP_DELAYPARSER_H
