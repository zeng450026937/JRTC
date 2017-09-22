#ifndef JXMPP_ERROR_H
#define JXMPP_ERROR_H

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class JXMPP_API Error {
        public:
            Error() {}
            JXMPP_DEFAULT_COPY_CONSTRUCTOR(Error)
            JXMPP_DEFAULT_COPY_ASSIGMNENT_OPERATOR(Error)
            virtual ~Error();
    };
}

#endif // JXMPP_ERROR_H
