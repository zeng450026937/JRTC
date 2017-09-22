#ifndef JXMPP_XMLPARSERCLIENT_H
#define JXMPP_XMLPARSERCLIENT_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/AttributeMap.h>

namespace JXMPP {
    class JXMPP_API XMLParserClient {
        public:
            virtual ~XMLParserClient();

            virtual void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) = 0;
            virtual void handleEndElement(const std::string& element, const std::string& ns) = 0;
            virtual void handleCharacterData(const std::string& data) = 0;
    };
}

#endif // JXMPP_XMLPARSERCLIENT_H
