#ifndef JXMPP_PAYLOADPARSERFACTORY_H
#define JXMPP_PAYLOADPARSERFACTORY_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/AttributeMap.h>

namespace JXMPP {

    class PayloadParser;

    /**
     * A factory for PayloadParsers.
     */
    class JXMPP_API PayloadParserFactory {
        public:
            virtual ~PayloadParserFactory();

            /**
             * Checks whether this factory can parse the given top-level element in the given namespace (with the given attributes).
             */
            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap& attributes) const = 0;

            /**
             * Creates a new payload parser.
             */
            virtual PayloadParser* createPayloadParser() = 0;
    };
}

#endif // JXMPP_PAYLOADPARSERFACTORY_H
