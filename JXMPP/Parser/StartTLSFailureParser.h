#ifndef JXMPP_STARTTLSFAILUREPARSER_H
#define JXMPP_STARTTLSFAILUREPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StartTLSFailure.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StartTLSFailureParser : public GenericElementParser<StartTLSFailure> {
        public:
            StartTLSFailureParser() : GenericElementParser<StartTLSFailure>() {}
    };
}

#endif // JXMPP_STARTTLSFAILUREPARSER_H
