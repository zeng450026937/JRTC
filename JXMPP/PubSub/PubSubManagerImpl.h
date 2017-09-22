#ifndef JXMPP_PUBSUBMANAGERIMPL_H
#define JXMPP_PUBSUBMANAGERIMPL_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/PubSub/PubSubManager.h>
#define JXMPP_PUBSUBMANAGERIMPL_DECLARE_CREATE_REQUEST(payload, container, response) \
    virtual std::shared_ptr< PubSubRequest<payload> >  \
            createRequest(IQ::Type type, const JID& receiver, std::shared_ptr<payload> p) override { \
        return std::make_shared< PubSubRequest<payload> >(type, receiver, p, router); \
    }

namespace JXMPP {
    class StanzaChannel;
    class Message;

    class JXMPP_API PubSubManagerImpl : public PubSubManager {
        public:
            PubSubManagerImpl(StanzaChannel* stanzaChannel, IQRouter* router);
            virtual ~PubSubManagerImpl() override;

            JXMPP_PUBSUB_FOREACH_PUBSUB_PAYLOAD_TYPE(
                    JXMPP_PUBSUBMANAGERIMPL_DECLARE_CREATE_REQUEST)

        private:
            void handleMessageRecevied(std::shared_ptr<Message>);

        private:
            StanzaChannel* stanzaChannel;
            IQRouter* router;
    };
}

#endif // JXMPP_PUBSUBMANAGERIMPL_H
