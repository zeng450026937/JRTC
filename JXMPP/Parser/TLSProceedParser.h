#ifndef JXMPP_TLSPROCEEDPARSER_H
#define JXMPP_TLSPROCEEDPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/TLSProceed.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API TLSProceedParser : public GenericElementParser<TLSProceed> {
        public:
            TLSProceedParser() : GenericElementParser<TLSProceed>() {}
    };
}

#endif // JXMPP_TLSPROCEEDPARSER_H
