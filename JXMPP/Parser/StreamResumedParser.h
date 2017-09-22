#ifndef JXMPP_STREAMRESUMEDPARSER_H
#define JXMPP_STREAMRESUMEDPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamResumed.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StreamResumedParser : public GenericElementParser<StreamResumed> {
        public:
            StreamResumedParser();
            ~StreamResumedParser();

            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&);
            virtual void handleEndElement(const std::string&, const std::string&);

        private:
            enum Level {
                TopLevel = 0
            };
            int level;
    };
}

#endif // JXMPP_STREAMRESUMEDPARSER_H
