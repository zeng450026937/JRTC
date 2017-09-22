#ifndef JXMPP_PAYLOADSPARSERTESTER_H
#define JXMPP_PAYLOADSPARSERTESTER_H

#include <cassert>

#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Parser/PayloadParser.h>
#include <JXMPP/Parser/PayloadParsers/FullPayloadParserFactoryCollection.h>
#include <JXMPP/Parser/PlatformXMLParserFactory.h>
#include <JXMPP/Parser/XMLParser.h>
#include <JXMPP/Parser/XMLParserClient.h>

namespace JXMPP {
    class PayloadsParserTester : public XMLParserClient {
        public:
            PayloadsParserTester() : level(0) {
                xmlParser = PlatformXMLParserFactory().createXMLParser(this);
            }

            bool parse(const std::string& data) {
                return xmlParser->parse(data);
            }

            virtual void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) {
                if (level == 0) {
                    assert(!payloadParser.get());
                    PayloadParserFactory* payloadParserFactory = factories.getPayloadParserFactory(element, ns, attributes);
                    assert(payloadParserFactory);
                    payloadParser.reset(payloadParserFactory->createPayloadParser());
                }
                payloadParser->handleStartElement(element, ns, attributes);
                level++;
            }

            virtual void handleEndElement(const std::string& element, const std::string& ns) {
                level--;
                payloadParser->handleEndElement(element, ns);
            }

            virtual void handleCharacterData(const std::string& data) {
                payloadParser->handleCharacterData(data);
            }

            std::shared_ptr<Payload> getPayload() const {
                return payloadParser->getPayload();
            }

            template<typename T>
            std::shared_ptr<T> getPayload() const {
                return std::dynamic_pointer_cast<T>(payloadParser->getPayload());
            }

        private:
            std::unique_ptr<XMLParser> xmlParser;
            FullPayloadParserFactoryCollection factories;
            std::shared_ptr<PayloadParser> payloadParser;
            int level;
    };
}

#endif // JXMPP_PAYLOADSPARSERTESTER_H
