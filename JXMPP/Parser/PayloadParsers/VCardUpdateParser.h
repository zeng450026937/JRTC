#ifndef JXMPP_VCARDUPDATEPARSER_H
#define JXMPP_VCARDUPDATEPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/VCardUpdate.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API VCardUpdateParser : public GenericPayloadParser<VCardUpdate> {
        public:
            VCardUpdateParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };
            int level_;
            std::string currentText_;
    };
}

#endif // JXMPP_VCARDUPDATEPARSER_H
