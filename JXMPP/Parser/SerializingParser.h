#ifndef JXMPP_SERIALIZINGPARSER_H
#define JXMPP_SERIALIZINGPARSER_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/AttributeMap.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API SerializingParser {
        public:
            SerializingParser();

            void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes);
            void handleEndElement(const std::string& element, const std::string& ns);
            void handleCharacterData(const std::string& data);

            std::string getResult() const;

        private:
            std::vector< std::shared_ptr<XMLElement> > elementStack_;
            std::shared_ptr<XMLElement> rootElement_;
    };
}

#endif // JXMPP_SERIALIZINGPARSER_H
