#ifndef JXMPP_PUBSUBMANAGER_H
#define JXMPP_PUBSUBMANAGER_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Elements/PubSub.h>
#include <JXMPP/Elements/PubSubAffiliations.h>
#include <JXMPP/Elements/PubSubCreate.h>
#include <JXMPP/Elements/PubSubDefault.h>
#include <JXMPP/Elements/PubSubEventPayload.h>
#include <JXMPP/Elements/PubSubItems.h>
#include <JXMPP/Elements/PubSubOwnerAffiliations.h>
#include <JXMPP/Elements/PubSubOwnerConfigure.h>
#include <JXMPP/Elements/PubSubOwnerDefault.h>
#include <JXMPP/Elements/PubSubOwnerDelete.h>
#include <JXMPP/Elements/PubSubOwnerPubSub.h>
#include <JXMPP/Elements/PubSubOwnerPurge.h>
#include <JXMPP/Elements/PubSubOwnerSubscriptions.h>
#include <JXMPP/Elements/PubSubPublish.h>
#include <JXMPP/Elements/PubSubRetract.h>
#include <JXMPP/Elements/PubSubSubscribe.h>
#include <JXMPP/Elements/PubSubSubscription.h>
#include <JXMPP/Elements/PubSubSubscriptions.h>
#include <JXMPP/Elements/PubSubUnsubscribe.h>
#include <JXMPP/PubSub/PubSubUtil.h>
#include <JXMPP/Queries/PubSubRequest.h>
#define JXMPP_PUBSUBMANAGER_DECLARE_CREATE_REQUEST(payload, container, response) \
    virtual std::shared_ptr< PubSubRequest<payload> >  \
        createRequest(IQ::Type, const JID&, std::shared_ptr<payload>) = 0;

namespace JXMPP {
    class JID;

    class JXMPP_API PubSubManager {
        public:
            virtual ~PubSubManager();

            JXMPP_PUBSUB_FOREACH_PUBSUB_PAYLOAD_TYPE(
                    JXMPP_PUBSUBMANAGER_DECLARE_CREATE_REQUEST)

            boost::signals2::signal<void (const JID&, const std::shared_ptr<PubSubEventPayload>)> onEvent;
    };
}

#endif // JXMPP_PUBSUBMANAGER_H
