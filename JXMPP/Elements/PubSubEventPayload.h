#ifndef JXMPP_PUBSUBEVENTPAYLOAD_H
#define JXMPP_PUBSUBEVENTPAYLOAD_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubEventPayload : public Payload {
        public:
            virtual ~PubSubEventPayload();
    };
}

#endif // JXMPP_PUBSUBEVENTPAYLOAD_H
