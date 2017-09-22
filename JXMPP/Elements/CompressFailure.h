#ifndef JXMPP_COMPRESSFAILURE_H
#define JXMPP_COMPRESSFAILURE_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ToplevelElement.h>

namespace JXMPP {
    class JXMPP_API CompressFailure : public ToplevelElement {
        public:
            CompressFailure() {}
    };
}

#endif // JXMPP_COMPRESSFAILURE_H
