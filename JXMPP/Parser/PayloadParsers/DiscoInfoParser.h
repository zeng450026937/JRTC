#ifndef JXMPP_DISCOINFOPARSER_H
#define JXMPP_DISCOINFOPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class FormParser;

    class JXMPP_API DiscoInfoParser : public GenericPayloadParser<DiscoInfo> {
        public:
            DiscoInfoParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };
            int level_;
            FormParser* formParser_;
    };
}

#endif // JXMPP_DISCOINFOPARSER_H
