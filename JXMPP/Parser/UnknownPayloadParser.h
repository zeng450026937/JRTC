#ifndef JXMPP_UNKNOWNPAYLOADPARSER_H
#define JXMPP_UNKNOWNPAYLOADPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParser.h>

namespace JXMPP {
    class JXMPP_API UnknownPayloadParser : public PayloadParser {
        public:
            UnknownPayloadParser() {}

            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&) {}
            virtual void handleEndElement(const std::string&, const std::string&) {}
            virtual void handleCharacterData(const std::string&) {}

            virtual std::shared_ptr<Payload> getPayload() const {
                return std::shared_ptr<Payload>();
            }
    };
}

#endif // JXMPP_UNKNOWNPAYLOADPARSER_H
