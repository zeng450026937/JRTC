#ifndef JXMPP_CARBONSENABLEPARSER_H
#define JXMPP_CARBONSENABLEPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsEnable.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API CarbonsEnableParser : public GenericPayloadParser<CarbonsEnable> {
        public:
            CarbonsEnableParser();
            virtual ~CarbonsEnableParser();
            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string&);
            virtual void handleCharacterData(const std::string&);
    };
}

#endif // JXMPP_CARBONSENABLEPARSER_H
