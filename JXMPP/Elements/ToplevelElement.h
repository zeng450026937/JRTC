#ifndef JXMPP_TOPLEVELELEMENT_H
#define JXMPP_TOPLEVELELEMENT_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Element.h>

namespace JXMPP {
    class JXMPP_API ToplevelElement : public Element {
        public:
            ToplevelElement() {}
            JXMPP_DEFAULT_COPY_CONSTRUCTOR(ToplevelElement)
            virtual ~ToplevelElement();
    };
}

#endif // JXMPP_TOPLEVELELEMENT_H
