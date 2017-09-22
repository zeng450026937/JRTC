#ifndef JXMPP_GENERICPAYLOADTREEPARSER_H
#define JXMPP_GENERICPAYLOADTREEPARSER_H

#include <deque>
#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/GenericPayloadParser.h>
#include <JXMPP/Parser/Tree/ParserElement.h>

namespace JXMPP {
    /**
     * Generic parser offering something a bit like a DOM to work with.
     */
    template<typename PAYLOAD_TYPE>
    class GenericPayloadTreeParser : public GenericPayloadParser<PAYLOAD_TYPE> {
        public:
            virtual void handleStartElement(const std::string& element, const std::string& xmlns, const AttributeMap& attributes) {
                if (!root_) {
                    root_ = std::make_shared<ParserElement>(element, xmlns, attributes);
                    elementStack_.push_back(root_);
                }
                else {
                    ParserElement::ref current = *elementStack_.rbegin();
                    elementStack_.push_back(current->addChild(element, xmlns, attributes));
                }
            }

            virtual void handleEndElement(const std::string& /*element*/, const std::string&) {
                elementStack_.pop_back();
                if (elementStack_.empty()) {
                    handleTree(root_);
                }
            }

            virtual void handleCharacterData(const std::string& data) {
                ParserElement::ref current = *elementStack_.rbegin();
                current->appendCharacterData(data);
            }

            virtual void handleTree(ParserElement::ref root) = 0;

        private:
            std::deque<ParserElement::ref> elementStack_;
            ParserElement::ref root_;
    };
}

#endif // JXMPP_GENERICPAYLOADTREEPARSER_H
