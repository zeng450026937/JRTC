#ifndef JXMPP_GENERICELEMENTPARSER_H
#define JXMPP_GENERICELEMENTPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/ElementParser.h>

namespace JXMPP {

    template<typename ElementType>
    class JXMPP_API GenericElementParser : public ElementParser {
        public:
            GenericElementParser() {
                stanza_ = std::make_shared<ElementType>();
            }

            virtual std::shared_ptr<ToplevelElement> getElement() const {
                return stanza_;
            }

            virtual std::shared_ptr<ElementType> getElementGeneric() const {
                return stanza_;
            }

        private:
            virtual void handleStartElement(const std::string&, const std::string&, const AttributeMap&) {
            }

            virtual void handleEndElement(const std::string&, const std::string&) {
            }

            virtual void handleCharacterData(const std::string&) {
            }

        private:
            std::shared_ptr<ElementType> stanza_;
    };
}

#endif // JXMPP_GENERICELEMENTPARSER_H
