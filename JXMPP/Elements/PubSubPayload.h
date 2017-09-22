#ifndef JXMPP_PUBSUBPAYLOAD_H
#define JXMPP_PUBSUBPAYLOAD_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubPayload : public Payload {
        public:
            virtual ~PubSubPayload();
    };
}

#endif // JXMPP_PUBSUBPAYLOAD_H
