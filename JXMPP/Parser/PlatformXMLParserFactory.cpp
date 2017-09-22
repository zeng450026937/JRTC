#include <JXMPP/Parser/PlatformXMLParserFactory.h>

#include <cassert>

#ifdef HAVE_LIBXML
#include <JXMPP/Parser/LibXMLParser.h>
#else
#include <JXMPP/Parser/ExpatParser.h>
#endif


namespace JXMPP {

PlatformXMLParserFactory::PlatformXMLParserFactory() {
}

std::unique_ptr<XMLParser> PlatformXMLParserFactory::createXMLParser(XMLParserClient* client) {
#ifdef HAVE_LIBXML
    return std::make_unique<LibXMLParser>(client);
#else
    return std::make_unique<ExpatParser>(client);
#endif
}

}