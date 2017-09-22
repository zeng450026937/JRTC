#ifndef JXMPP_IBBPARSER_H
#define JXMPP_IBBPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IBB.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API IBBParser : public GenericPayloadParser<IBB> {
        public:
            IBBParser();
            ~IBBParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0
            };
            int level;
            std::string currentText;
    };
}

#endif // JXMPP_IBBPARSER_H
