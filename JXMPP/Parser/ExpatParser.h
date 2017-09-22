#ifndef JXMPP_EXPATPARSER_H
#define JXMPP_EXPATPARSER_H

#include <memory>

#include <boost/noncopyable.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/XMLParser.h>

namespace JXMPP {
    class JXMPP_API ExpatParser : public XMLParser, public boost::noncopyable {
        public:
            ExpatParser(XMLParserClient* client);
            ~ExpatParser();

            bool parse(const std::string& data);

            void stopParser();

        private:
            struct Private;
            const std::unique_ptr<Private> p;
    };
}

#endif // JXMPP_EXPATPARSER_H
