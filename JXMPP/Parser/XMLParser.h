#ifndef JXMPP_XMLPARSER_H
#define JXMPP_XMLPARSER_H

#include <string>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class XMLParserClient;

    class JXMPP_API XMLParser {
        public:
            XMLParser(XMLParserClient* client);
            virtual ~XMLParser();

            virtual bool parse(const std::string& data) = 0;

            XMLParserClient* getClient() const {
                return client_;
            }

        private:
            XMLParserClient* client_;
    };
}

#endif // JXMPP_XMLPARSER_H
