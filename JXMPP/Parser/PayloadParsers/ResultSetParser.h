#ifndef JXMPP_RESULTSETPARSER_H
#define JXMPP_RESULTSETPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ResultSet.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API ResultSetParser : public GenericPayloadParser<ResultSet> {
        public:
            ResultSetParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };

        private:
            std::string currentText_;
            int level_;
    };
}

#endif // JXMPP_RESULTSETPARSER_H
