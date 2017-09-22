#ifndef JXMPP_PUBSUBREQUEST_H
#define JXMPP_PUBSUBREQUEST_H

#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ContainerPayload.h>
#include <JXMPP/Elements/PubSub.h>
#include <JXMPP/Elements/PubSubAffiliations.h>
#include <JXMPP/Elements/PubSubCreate.h>
#include <JXMPP/Elements/PubSubDefault.h>
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
#include <JXMPP/Queries/Request.h>

namespace JXMPP {
    namespace Detail {
        template<typename T>
        struct PubSubPayloadTraits;

#define JXMPP_PUBSUB_DECLARE_PAYLOAD_TRAITS(PAYLOAD, CONTAINER, RESPONSE) \
        template<> struct PubSubPayloadTraits< PAYLOAD > { \
            typedef CONTAINER ContainerType; \
            typedef RESPONSE ResponseType; \
        };

        JXMPP_PUBSUB_FOREACH_PUBSUB_PAYLOAD_TYPE(
                JXMPP_PUBSUB_DECLARE_PAYLOAD_TRAITS)
    }

    template<typename T>
    class JXMPP_API PubSubRequest : public Request {
            typedef typename Detail::PubSubPayloadTraits<T>::ContainerType ContainerType;
            typedef typename Detail::PubSubPayloadTraits<T>::ResponseType ResponseType;

        public:
            PubSubRequest(
                    IQ::Type type,
                    const JID& receiver,
                    std::shared_ptr<T> payload,
                    IQRouter* router) :
                        Request(type, receiver, router) {
                std::shared_ptr<ContainerType> wrapper = std::make_shared<ContainerType>();
                wrapper->setPayload(payload);
                setPayload(wrapper);
            }

            PubSubRequest(
                    IQ::Type type,
                    const JID& sender,
                    const JID& receiver,
                    std::shared_ptr<T> payload,
                    IQRouter* router) :
                        Request(type, sender, receiver, router) {
                std::shared_ptr<ContainerType> wrapper = std::make_shared<ContainerType>();
                wrapper->setPayload(payload);
                setPayload(wrapper);
            }

            virtual void handleResponse(
                    std::shared_ptr<Payload> payload, ErrorPayload::ref error) {
                std::shared_ptr<ResponseType> result;
                if (std::shared_ptr<ContainerType> container = std::dynamic_pointer_cast<ContainerType>(payload)) {
                    result = std::dynamic_pointer_cast<ResponseType>(container->getPayload());
                }
                onResponse(result, error);
            }

        public:
            boost::signals2::signal<void (std::shared_ptr<ResponseType>, ErrorPayload::ref)> onResponse;
    };
}

#endif // JXMPP_PUBSUBREQUEST_H
