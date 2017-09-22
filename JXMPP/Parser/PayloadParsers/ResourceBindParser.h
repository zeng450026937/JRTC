#ifndef JXMPP_RESOURCEBINDPARSER_H
#define JXMPP_RESOURCEBINDPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ResourceBind.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API ResourceBindParser : public GenericPayloadParser<ResourceBind> {
        public:
            ResourceBindParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
            bool inJID_;
            bool inResource_;
            std::string text_;
    };
}

#endif // JXMPP_RESOURCEBINDPARSER_H
