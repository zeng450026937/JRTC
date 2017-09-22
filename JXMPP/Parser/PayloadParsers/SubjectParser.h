#ifndef JXMPP_SUBJECTPARSER_H
#define JXMPP_SUBJECTPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Subject.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API SubjectParser : public GenericPayloadParser<Subject> {
        public:
            SubjectParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
            std::string text_;
    };
}

#endif // JXMPP_SUBJECTPARSER_H
