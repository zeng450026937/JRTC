#ifndef JXMPP_PUBSUBERRORPARSER_H
#define JXMPP_PUBSUBERRORPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/PubSubError.h>
#include <JXMPP/Parser/EnumParser.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API PubSubErrorParser : public GenericPayloadParser<PubSubError> {
        public:
            PubSubErrorParser();
            virtual ~PubSubErrorParser() override;

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes) override;
            virtual void handleEndElement(const std::string& element, const std::string&) override;
            virtual void handleCharacterData(const std::string& data) override;

        private:
            int level;
            EnumParser<PubSubError::Type> typeParser;
            EnumParser<PubSubError::UnsupportedFeatureType> unsupportedTypeParser;
    };
}

#endif // JXMPP_PUBSUBERRORPARSER_H
