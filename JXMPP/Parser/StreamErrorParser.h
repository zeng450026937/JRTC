#ifndef JXMPP_STREAMERRORPARSER_H
#define JXMPP_STREAMERRORPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamError.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StreamErrorParser : public GenericElementParser<StreamError> {
        public:
            StreamErrorParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                ElementLevel = 1
            };
            int level;
            std::string currentText;
    };
}

#endif // JXMPP_STREAMERRORPARSER_H
