#ifndef JXMPP_PLATFORMXMLPARSERFACTORY_H
#define JXMPP_PLATFORMXMLPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/XMLParserFactory.h>

namespace JXMPP {
    class JXMPP_API PlatformXMLParserFactory : public XMLParserFactory {
        public:
            PlatformXMLParserFactory();

            virtual std::unique_ptr<XMLParser> createXMLParser(XMLParserClient*);
    };
}

#endif // JXMPP_PLATFORMXMLPARSERFACTORY_H
