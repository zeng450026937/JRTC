#ifndef JXMPP_XMPPPARSER_H
#define JXMPP_XMPPPARSER_H

#include <memory>

#include <boost/noncopyable.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/AttributeMap.h>
#include <JXMPP/Parser/XMLParserClient.h>

namespace JXMPP {
    class XMLParser;
    class XMPPParserClient;
    class XMLParserFactory;
    class ElementParser;
    class PayloadParserFactoryCollection;

    class JXMPP_API XMPPParser : public XMLParserClient, boost::noncopyable {
        public:
            XMPPParser(
                    XMPPParserClient* parserClient,
                    PayloadParserFactoryCollection* payloadParserFactories,
                    XMLParserFactory* xmlParserFactory);
            virtual ~XMPPParser();

            bool parse(const std::string&);

        private:
            virtual void handleStartElement(
                    const std::string& element,
                    const std::string& ns,
                    const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string& ns);
            virtual void handleCharacterData(const std::string& data);

            ElementParser* createElementParser(const std::string& element, const std::string& xmlns);

        private:
            std::unique_ptr<XMLParser> xmlParser_;
            XMPPParserClient* client_;
            PayloadParserFactoryCollection* payloadParserFactories_;
            enum Level {
                TopLevel = 0,
                StreamLevel = 1,
                ElementLevel = 2
            };
            int level_;
            ElementParser* currentElementParser_;
            bool parseErrorOccurred_;
    };
}

#endif // JXMPP_XMPPPARSER_H
