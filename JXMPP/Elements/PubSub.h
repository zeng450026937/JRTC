#ifndef JXMPP_PUBSUB_H
#define JXMPP_PUBSUB_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ContainerPayload.h>
#include <JXMPP/Elements/PubSubPayload.h>

namespace JXMPP {
    class JXMPP_API PubSub : public ContainerPayload<PubSubPayload> {
        public:
            PubSub();
            virtual ~PubSub();
    };
}

#endif // JXMPP_PUBSUB_H
