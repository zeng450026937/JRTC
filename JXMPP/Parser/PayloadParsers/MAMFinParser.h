#ifndef JXMPP_MAMFINPARSER_H
#define JXMPP_MAMFINPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MAMFin.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class ResultSetParser;

    class JXMPP_API MAMFinParser : public GenericPayloadParser<MAMFin> {
        public:
            MAMFinParser();

            virtual void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };

        private:
            std::shared_ptr<ResultSetParser> resultSetParser_;
            int level_;
    };
}

#endif // JXMPP_MAMFINPARSER_H
