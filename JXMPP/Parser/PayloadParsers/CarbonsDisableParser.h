#ifndef JXMPP_CARBONSDISABLEPARSER_H
#define JXMPP_CARBONSDISABLEPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsDisable.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API CarbonsDisableParser : public GenericPayloadParser<CarbonsDisable> {
        public:
            CarbonsDisableParser();
            virtual ~CarbonsDisableParser();

            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string&);
            virtual void handleCharacterData(const std::string&);
    };
}

#endif // JXMPP_CARBONSDISABLEPARSER_H
