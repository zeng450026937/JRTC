#ifndef JXMPP_STARTTLSPARSER_H
#define JXMPP_STARTTLSPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StartTLSRequest.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API StartTLSParser : public GenericElementParser<StartTLSRequest> {
        public:
            StartTLSParser() : GenericElementParser<StartTLSRequest>() {}
    };
}

#endif // JXMPP_STARTTLSPARSER_H
