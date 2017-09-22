#ifndef JXMPP_ELEMENTPARSER_H
#define JXMPP_ELEMENTPARSER_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>
#include <JXMPP/Parser/AttributeMap.h>

namespace JXMPP {
    class JXMPP_API ElementParser {
        public:
            virtual ~ElementParser();

            virtual void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) = 0;
            virtual void handleEndElement(const std::string& element, const std::string& ns) = 0;
            virtual void handleCharacterData(const std::string& data) = 0;

            virtual std::shared_ptr<ToplevelElement> getElement() const = 0;
    };
}

#endif // JXMPP_ELEMENTPARSER_H
