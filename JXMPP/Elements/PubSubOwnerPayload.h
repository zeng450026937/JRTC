#ifndef JXMPP_PUBSUBOWNERPAYLOAD_H
#define JXMPP_PUBSUBOWNERPAYLOAD_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerPayload : public Payload {
        public:
            virtual ~PubSubOwnerPayload();
    };
}

#endif // JXMPP_PUBSUBOWNERPAYLOAD_H
