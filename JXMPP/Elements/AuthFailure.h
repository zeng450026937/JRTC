#ifndef JXMPP_AUTHFAILURE_H
#define JXMPP_AUTHFAILURE_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API AuthFailure : public ToplevelElement {
        public:
            typedef std::shared_ptr<AuthFailure> ref;

            AuthFailure() {}
    };
}

#endif // JXMPP_AUTHFAILURE_H
