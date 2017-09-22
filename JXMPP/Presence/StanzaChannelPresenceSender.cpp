#include <JXMPP/Presence/StanzaChannelPresenceSender.h>

#include <JXMPP/Client/StanzaChannel.h>

namespace JXMPP {

StanzaChannelPresenceSender::StanzaChannelPresenceSender(StanzaChannel* channel) : channel(channel) {
}

void StanzaChannelPresenceSender::sendPresence(Presence::ref presence) {
    channel->sendPresence(presence);
}

bool StanzaChannelPresenceSender::isAvailable() const {
    return channel->isAvailable();
}

}
