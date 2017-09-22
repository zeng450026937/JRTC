#ifndef JXMPP_DOMAINNAMERESOLVEERROR_H
#define JXMPP_DOMAINNAMERESOLVEERROR_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/Error.h>

namespace JXMPP {
    class JXMPP_API DomainNameResolveError : public Error {
        public:
            DomainNameResolveError() {}
            JXMPP_DEFAULT_COPY_CONSTRUCTOR(DomainNameResolveError)
            JXMPP_DEFAULT_COPY_ASSIGMNENT_OPERATOR(DomainNameResolveError)
    };
}

#endif // JXMPP_DOMAINNAMERESOLVEERROR_H
