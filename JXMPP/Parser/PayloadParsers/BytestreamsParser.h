#ifndef JXMPP_BYTESTREAMSPARSER_H
#define JXMPP_BYTESTREAMSPARSER_H

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Bytestreams.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API BytestreamsParser : public GenericPayloadParser<Bytestreams> {
        public:
            BytestreamsParser();
            ~BytestreamsParser();

            virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
            virtual void handleEndElement(const std::string& element, const std::string&);
            virtual void handleCharacterData(const std::string& data);

        private:
            enum Level {
                TopLevel = 0,
                PayloadLevel = 1
            };
            int level;
    };
}

#endif // JXMPP_BYTESTREAMSPARSER_H
