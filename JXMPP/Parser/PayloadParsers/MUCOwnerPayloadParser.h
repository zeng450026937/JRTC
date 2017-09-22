#ifndef JXMPP_MUCOWNERPAYLOADPARSER_H
#define JXMPP_MUCOWNERPAYLOADPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCOwnerPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;

    class JXMPP_API MUCOwnerPayloadParser : public GenericPayloadParser<MUCOwnerPayload> {
        public:
        MUCOwnerPayloadParser(PayloadParserFactoryCollection* factories);

        private:
            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            PayloadParserFactoryCollection* factories;
            int level;
            std::shared_ptr<PayloadParser> currentPayloadParser;
    };
}

#endif // JXMPP_MUCOWNERPAYLOADPARSER_H
