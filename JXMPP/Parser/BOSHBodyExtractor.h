#ifndef JXMPP_BOSHBODYEXTRACTOR_H
#define JXMPP_BOSHBODYEXTRACTOR_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Parser/XMLParserClient.h>

namespace JXMPP {
    class XMLParserFactory;

    class JXMPP_API BOSHBodyExtractor {
            friend class BOSHBodyParserClient;
        public:
            struct BOSHBody {
                AttributeMap attributes;
                std::string content;
            };

            BOSHBodyExtractor(XMLParserFactory* parserFactory, const ByteArray& data);

            const boost::optional<BOSHBody>& getBody() const {
                return body;
            }

        private:
            boost::optional<BOSHBody> body;
    };
}

#endif // JXMPP_BOSHBODYEXTRACTOR_H
