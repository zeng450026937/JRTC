#ifndef JXMPP_STARTTLSFAILURE_H
#define JXMPP_STARTTLSFAILURE_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API StartTLSFailure : public ToplevelElement {
        public:
            StartTLSFailure() {}
    };
}

#endif // JXMPP_STARTTLSFAILURE_H
