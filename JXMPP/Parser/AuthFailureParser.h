#ifndef JXMPP_AUTHFAILUREPARSER_H
#define JXMPP_AUTHFAILUREPARSER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthFailure.h>
#include <JXMPP/Parser/GenericElementParser.h>

namespace JXMPP {
    class JXMPP_API AuthFailureParser : public GenericElementParser<AuthFailure> {
        public:
            AuthFailureParser() : GenericElementParser<AuthFailure>() {}
    };
}

#endif // JXMPP_AUTHFAILUREPARSER_H
