#ifndef JXMPP_PAYLOADPARSER_H
#define JXMPP_PAYLOADPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Parser/AttributeMap.h>

namespace JXMPP {


    /**
     * A parser for XMPP stanza payloads.
     *
     * The parser is event driven: handleStartElement, handleEndElement, and handleCharacterData will be called
     * when the parser detects start and end of XML elements, or character data.
     * After the data for the given top-level element is processed, getPayload() will be called to retrieve the
     * payload.
     */
    class JXMPP_API PayloadParser {
        public:
            virtual ~PayloadParser();

            /**
             * Handle the start of an XML element.
             */
            virtual void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes) = 0;

            /**
             * Handle the end of an XML element.
             */
            virtual void handleEndElement(const std::string& element, const std::string& ns) = 0;

            /**
             * Handle character data.
             */
            virtual void handleCharacterData(const std::string& data) = 0;

            /**
             * Retrieve a pointer to the payload.
             */
            virtual std::shared_ptr<Payload> getPayload() const = 0;
    };
}

#endif // JXMPP_PAYLOADPARSER_H
