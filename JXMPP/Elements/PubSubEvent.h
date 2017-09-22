#ifndef JXMPP_PUBSUBEVENT_H
#define JXMPP_PUBSUBEVENT_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ContainerPayload.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/PubSubEventPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubEvent : public ContainerPayload<PubSubEventPayload> {
        public:
            PubSubEvent();
            virtual ~PubSubEvent();
    };
}

#endif // JXMPP_PUBSUBEVENT_H
