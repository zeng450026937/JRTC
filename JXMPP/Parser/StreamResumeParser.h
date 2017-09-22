#ifndef JXMPP_STREAMRESUMEPARSER_H
#define JXMPP_STREAMRESUMEPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamResume.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StreamResumeParser : public GenericElementParser<StreamResume> {
        public:
            StreamResumeParser();
            ~StreamResumeParser();

            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string&);

        private:
            enum Level {
                TopLevel = 0
            };
            int level;
    };
}

#endif // JXMPP_STREAMRESUMEPARSER_H
