#ifndef JXMPP_COMPRESSPARSER_H
#define JXMPP_COMPRESSPARSER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CompressRequest.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API CompressParser : public GenericElementParser<CompressRequest> {
        public:
            CompressParser();

        private:
            void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes);
            void handleEndElement(const std::string& element, const std::string& ns);
            void handleCharacterData(const std::string& data);

        private:
            int currentDepth_;
            std::string currentText_;
            bool inMethod_;
    };
}

#endif // JXMPP_COMPRESSPARSER_H
