#ifndef JXMPP_RAWXMLPAYLOADPARSER_H
#define JXMPP_RAWXMLPAYLOADPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RawXMLPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>
#include <JXMPP/Parser/SerializingParser.h>

namespace JXMPP {
    class SerializingParser;

    class JXMPP_API RawXMLPayloadParser : public GenericPayloadParser<RawXMLPayload> {
        public:
            RawXMLPayloadParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            int level_;
            SerializingParser serializingParser_;
    };
}

#endif // JXMPP_RAWXMLPAYLOADPARSER_H
