#ifndef JXMPP_GENERICSTANZAPARSER_H
#define JXMPP_GENERICSTANZAPARSER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Parser/StanzaParser.h>

namespace JXMPP {

    class PayloadParserFactoryCollection;

    template<typename STANZA_TYPE>
    class JXMPP_API GenericStanzaParser : public StanzaParser {
        public:
            GenericStanzaParser(PayloadParserFactoryCollection* collection) :
                        StanzaParser(collection) {
                stanza_ = std::make_shared<STANZA_TYPE>();
            }

            virtual std::shared_ptr<ToplevelElement> getElement() const {
                return stanza_;
            }

            virtual std::shared_ptr<STANZA_TYPE> getStanzaGeneric() const {
                return stanza_;
            }

        private:
            std::shared_ptr<STANZA_TYPE> stanza_;
    };
}

#endif // JXMPP_GENERICSTANZAPARSER_H
