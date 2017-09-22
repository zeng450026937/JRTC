#ifndef JXMPP_MAMQUERYPARSER_H
#define JXMPP_MAMQUERYPARSER_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MAMQuery.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class ResultSetParser;
    class FormParser;

    class JXMPP_API MAMQueryParser : public GenericPayloadParser<MAMQuery> {
        public:
            MAMQueryParser();

            virtual void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };

        private:
            std::shared_ptr<FormParser> formParser_;
            std::shared_ptr<ResultSetParser> resultSetParser_;
            int level_;
    };
}

#endif // JXMPP_MAMQUERYPARSER_H
