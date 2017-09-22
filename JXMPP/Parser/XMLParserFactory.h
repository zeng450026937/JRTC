#ifndef JXMPP_XMLPARSERFACTORY_H
#define JXMPP_XMLPARSERFACTORY_H

#include <memory>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class XMLParser;
    class XMLParserClient;

    class JXMPP_API XMLParserFactory {
        public:
            virtual ~XMLParserFactory();

            virtual std::unique_ptr<XMLParser> createXMLParser(XMLParserClient*) = 0;
    };
}

#endif // JXMPP_XMLPARSERFACTORY_H
