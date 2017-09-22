#ifndef JXMPP_LIBXMLPARSER_H
#define JXMPP_LIBXMLPARSER_H

#include <memory>

#include <boost/noncopyable.hpp>

#include <JXMPP/Parser/XMLParser.h>

namespace JXMPP {
    /**
     * Warning: This constructor is not thread-safe, because it depends on global state to
     * check whether it is initialized.
     */
    class LibXMLParser : public XMLParser, public boost::noncopyable {
        public:
            LibXMLParser(XMLParserClient* client);
            virtual ~LibXMLParser();

            bool parse(const std::string& data);

        private:
            static bool initialized;

            struct Private;
            const std::unique_ptr<Private> p;
    };
}

#endif // JXMPP_LIBXMLPARSER_H
