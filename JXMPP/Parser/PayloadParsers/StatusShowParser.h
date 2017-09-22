#ifndef JXMPP_STATUSSHOWPARSER_H
#define JXMPP_STATUSSHOWPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StatusShow.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API StatusShowParser : public GenericPayloadParser<StatusShow> {
        public:
            StatusShowParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
            std::string text_;
    };
}

#endif // JXMPP_STATUSSHOWPARSER_H
