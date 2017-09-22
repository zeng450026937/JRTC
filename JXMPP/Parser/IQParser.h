#ifndef JXMPP_IQPARSER_H
#define JXMPP_IQPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Parser/GenericStanzaParser.h>

namespace JXMPP {
    class JXMPP_API IQParser : public GenericStanzaParser<IQ> {
        public:
            IQParser(PayloadParserFactoryCollection* factories);

        private:
            virtual void handleStanzaAttributes(const AttributeMap&);
    };
}

#endif // JXMPP_IQPARSER_H
