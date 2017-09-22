#include <JXMPP/Presence/PayloadAddingPresenceSender.h>

namespace JXMPP {

PayloadAddingPresenceSender::PayloadAddingPresenceSender(PresenceSender* sender) : sender(sender) {
}

void PayloadAddingPresenceSender::sendPresence(Presence::ref presence) {
    if (presence->isAvailable()) {
        if (!presence->getTo().isValid()) {
            lastSentPresence = presence;
        }
    }
    else {
        lastSentPresence.reset();
    }
    if (payload) {
        Presence::ref sentPresence = Presence::create(presence);
        sentPresence->updatePayload(payload);
        sender->sendPresence(sentPresence);
    }
    else {
        sender->sendPresence(presence);
    }
}

bool PayloadAddingPresenceSender::isAvailable() const {
    return sender->isAvailable();
}

void PayloadAddingPresenceSender::setPayload(std::shared_ptr<Payload> payload) {
    this->payload = payload;
    if (lastSentPresence) {
        sendPresence(lastSentPresence);
    }
}

void PayloadAddingPresenceSender::reset() {
    lastSentPresence.reset();
}

}
