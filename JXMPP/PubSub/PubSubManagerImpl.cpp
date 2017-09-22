#include <JXMPP/PubSub/PubSubManagerImpl.h>

#include <boost/bind.hpp>

#include <JXMPP/Client/StanzaChannel.h>
#include <JXMPP/Elements/Message.h>
#include <JXMPP/Elements/PubSubEvent.h>

using namespace JXMPP;

PubSubManagerImpl::PubSubManagerImpl(StanzaChannel* stanzaChannel, IQRouter* router) :
        stanzaChannel(stanzaChannel),
        router(router) {
    stanzaChannel->onMessageReceived.connect(boost::bind(&PubSubManagerImpl::handleMessageRecevied, this, _1));
}

PubSubManagerImpl::~PubSubManagerImpl() {
    stanzaChannel->onMessageReceived.disconnect(boost::bind(&PubSubManagerImpl::handleMessageRecevied, this, _1));
}

void PubSubManagerImpl::handleMessageRecevied(std::shared_ptr<Message> message) {
    if (std::shared_ptr<PubSubEvent> event = message->getPayload<PubSubEvent>()) {
        onEvent(message->getFrom(), event->getPayload());
    }
}
