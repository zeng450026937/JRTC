#include <JXMPP/StreamManagement/StanzaAckResponder.h>

#include <boost/numeric/conversion/cast.hpp>

namespace JXMPP {

static const unsigned int MAX_HANDLED_STANZA_COUNT = boost::numeric_cast<unsigned int>((1ULL<<32) - 1);

StanzaAckResponder::StanzaAckResponder() : handledStanzasCount(0) {
}

void StanzaAckResponder::handleStanzaReceived() {
    handledStanzasCount = (handledStanzasCount == MAX_HANDLED_STANZA_COUNT ? 0 : handledStanzasCount + 1);
}

void StanzaAckResponder::handleAckRequestReceived() {
    onAck(handledStanzasCount);
}

}
