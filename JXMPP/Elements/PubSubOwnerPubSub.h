#ifndef JXMPP_PUBSUBOWNERPUBSUB_H
#define JXMPP_PUBSUBOWNERPUBSUB_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ContainerPayload.h>
#include <JXMPP/Elements/PubSubOwnerPayload.h>

namespace JXMPP {
    class JXMPP_API PubSubOwnerPubSub : public ContainerPayload<PubSubOwnerPayload> {
        public:
            PubSubOwnerPubSub();
            virtual ~PubSubOwnerPubSub();
    };
}

#endif // JXMPP_PUBSUBOWNERPUBSUB_H
