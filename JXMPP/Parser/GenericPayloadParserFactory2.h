#ifndef JXMPP_GENERICPAYLOADPARSERFACTORY2_H
#define JXMPP_GENERICPAYLOADPARSERFACTORY2_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/PayloadParserFactory.h>

namespace JXMPP {
    class PayloadParserFactoryCollection;

    /**
     * A generic class for PayloadParserFactories that parse a specific payload (given as the template parameter of the class).
     */
    template<typename PARSER_TYPE>
    class GenericPayloadParserFactory2 : public PayloadParserFactory {
        public:
            /**
             * Construct a parser factory that can parse the given top-level tag in the given namespace.
             */
            GenericPayloadParserFactory2(const std::string& tag, const std::string& xmlns, PayloadParserFactoryCollection* parsers) : tag_(tag), xmlns_(xmlns), parsers_(parsers) {}

            virtual bool canParse(const std::string& element, const std::string& ns, const AttributeMap&) const {
                return (tag_.empty() ? true : element == tag_) && (xmlns_.empty() ? true : xmlns_ == ns);
            }

            virtual PayloadParser* createPayloadParser() {
                return new PARSER_TYPE(parsers_);
            }

        private:
            std::string tag_;
            std::string xmlns_;
            PayloadParserFactoryCollection* parsers_;
    };
}

#endif // JXMPP_GENERICPAYLOADPARSERFACTORY2_H
