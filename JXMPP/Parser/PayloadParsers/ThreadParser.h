#ifndef JXMPP_THREADPARSER_H
#define JXMPP_THREADPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Thread.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API ThreadParser : public GenericPayloadParser<Thread> {
        public:
            ThreadParser();
            virtual ~ThreadParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
            std::string text_;
    };
}

#endif // JXMPP_THREADPARSER_H
