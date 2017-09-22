#ifndef JXMPP_UNKNOWNELEMENT_H
#define JXMPP_UNKNOWNELEMENT_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API UnknownElement : public ToplevelElement {
        public:
            UnknownElement() {}
    };
}

#endif // JXMPP_UNKNOWNELEMENT_H
