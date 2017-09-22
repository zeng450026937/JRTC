#ifndef JXMPP_STANZAPARSER_H
#define JXMPP_STANZAPARSER_H

#include <memory>
#include <string>

#include <boost/noncopyable.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Stanza.h>
#include <JXMPP/Parser/AttributeMap.h>
#include <JXMPP/Parser/ElementParser.h>

namespace JXMPP {
    class PayloadParser;
    class PayloadParserFactoryCollection;

    class JXMPP_API StanzaParser : public ElementParser, public boost::noncopyable {
        public:
            StanzaParser(PayloadParserFactoryCollection* factories);
            ~StanzaParser();

            void handleStartElement(const std::string& element, const std::string& ns, const AttributeMap& attributes);
            void handleEndElement(const std::string& element, const std::string& ns);
            void handleCharacterData(const std::string& data);

            virtual std::shared_ptr<ToplevelElement> getElement() const = 0;
            virtual void handleStanzaAttributes(const AttributeMap&) {}

            virtual std::shared_ptr<Stanza> getStanza() const {
                return std::dynamic_pointer_cast<Stanza>(getElement());
            }

        private:
            bool inPayload() const {
                return currentDepth_ > 1;
            }

            bool inStanza() const {
                return currentDepth_ > 0;
            }


        private:
            int currentDepth_;
            PayloadParserFactoryCollection* factories_;
            std::shared_ptr<PayloadParser> currentPayloadParser_;
    };
}

#endif // JXMPP_STANZAPARSER_H
