#ifndef JXMPP_CARBONSPRIVATEPARSER_H
#define JXMPP_CARBONSPRIVATEPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsPrivate.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API CarbonsPrivateParser : public GenericPayloadParser<CarbonsPrivate> {
        public:
            CarbonsPrivateParser();
            virtual ~CarbonsPrivateParser();
            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string&);
            virtual void handleCharacterData(const std::string&);
    };
}

#endif // JXMPP_CARBONSPRIVATEPARSER_H
