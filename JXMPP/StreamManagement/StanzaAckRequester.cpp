#include <JXMPP/StreamManagement/StanzaAckRequester.h>

#include <boost/numeric/conversion/cast.hpp>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Elements/Message.h>

namespace JXMPP {

static const unsigned int MAX_HANDLED_STANZA_COUNT = boost::numeric_cast<unsigned int>((1ULL<<32) - 1);

StanzaAckRequester::StanzaAckRequester() : lastHandledStanzasCount(0) {

}

void StanzaAckRequester::handleStanzaSent(std::shared_ptr<Stanza> stanza) {
    unackedStanzas.push_back(stanza);
    if (std::dynamic_pointer_cast<Message>(stanza)) {
        onRequestAck();
    }
}

void StanzaAckRequester::handleAckReceived(unsigned int handledStanzasCount) {
    unsigned int i = lastHandledStanzasCount;
    while (i != handledStanzasCount) {
        if (unackedStanzas.empty()) {
            JXMPP_LOG(warning) << "Server acked more stanzas than we sent" << std::endl;
            break;
        }
        std::shared_ptr<Stanza> ackedStanza = unackedStanzas.front();
        unackedStanzas.pop_front();
        onStanzaAcked(ackedStanza);
        i = (i == MAX_HANDLED_STANZA_COUNT ? 0 : i + 1);
    }
    lastHandledStanzasCount = handledStanzasCount;
}

}
