#ifndef JXMPP_STARTSESSION_H
#define JXMPP_STARTSESSION_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API StartSession : public Payload {
        public:
            StartSession() {}
    };
}

#endif // JXMPP_STARTSESSION_H
