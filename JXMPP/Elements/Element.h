#ifndef JXMPP_ELEMENT_H
#define JXMPP_ELEMENT_H

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API Element {
        public:
            Element() {}
            JXMPP_DEFAULT_COPY_CONSTRUCTOR(Element)
            virtual ~Element();

            JXMPP_DEFAULT_COPY_ASSIGMNENT_OPERATOR(Element)
    };
}

#endif // JXMPP_ELEMENT_H
