#include <JXMPP/Presence/SubscriptionManager.h>

#include <boost/bind.hpp>

#include <JXMPP/Client/StanzaChannel.h>

namespace JXMPP {

SubscriptionManager::SubscriptionManager(StanzaChannel* channel) : stanzaChannel(channel) {
    stanzaChannel->onPresenceReceived.connect(boost::bind(&SubscriptionManager::handleIncomingPresence, this, _1));
}

SubscriptionManager::~SubscriptionManager() {
    stanzaChannel->onPresenceReceived.disconnect(boost::bind(&SubscriptionManager::handleIncomingPresence, this, _1));
}

void SubscriptionManager::cancelSubscription(const JID& jid) {
    Presence::ref stanza(new Presence());
    stanza->setType(Presence::Unsubscribed);
    stanza->setTo(jid);
    stanzaChannel->sendPresence(stanza);
}

void SubscriptionManager::confirmSubscription(const JID& jid) {
    Presence::ref stanza(new Presence());
    stanza->setType(Presence::Subscribed);
    stanza->setTo(jid);
    stanzaChannel->sendPresence(stanza);
}


void SubscriptionManager::requestSubscription(const JID& jid) {
    Presence::ref stanza(new Presence());
    stanza->setType(Presence::Subscribe);
    stanza->setTo(jid);
    stanzaChannel->sendPresence(stanza);
}

void SubscriptionManager::handleIncomingPresence(Presence::ref presence) {
    JID bareJID(presence->getFrom().toBare());
    if (presence->getType() == Presence::Subscribe) {
        onPresenceSubscriptionRequest(bareJID, presence->getStatus(), presence);
    }
    else if (presence->getType() == Presence::Unsubscribe) {
        onPresenceSubscriptionRevoked(bareJID, presence->getStatus());
    }
}


}
