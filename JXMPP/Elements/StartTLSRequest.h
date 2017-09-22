#ifndef JXMPP_STARTTLSREQUEST_H
#define JXMPP_STARTTLSREQUEST_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API StartTLSRequest : public ToplevelElement {
        public:
            StartTLSRequest() {}
    };
}

#endif // JXMPP_STARTTLSREQUEST_H
