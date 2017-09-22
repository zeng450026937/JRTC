#include <JXMPP/LinkLocal/OutgoingLinkLocalSession.h>

#include <boost/bind.hpp>

#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Elements/ProtocolHeader.h>
#include <JXMPP/Elements/StreamFeatures.h>
#include <JXMPP/StreamStack/XMPPLayer.h>

namespace JXMPP {

OutgoingLinkLocalSession::OutgoingLinkLocalSession(
        const JID& localJID,
        const JID& remoteJID,
        std::shared_ptr<Connection> connection,
        PayloadParserFactoryCollection* payloadParserFactories,
        PayloadSerializerCollection* payloadSerializers,
        XMLParserFactory* xmlParserFactory) :
            Session(connection, payloadParserFactories, payloadSerializers, xmlParserFactory) {
    setLocalJID(localJID);
    setRemoteJID(remoteJID);
}

void OutgoingLinkLocalSession::handleSessionStarted() {
    ProtocolHeader header;
    header.setFrom(getLocalJID());
    getXMPPLayer()->writeHeader(header);
}

void OutgoingLinkLocalSession::handleStreamStart(const ProtocolHeader&) {
    for (const auto& stanza : queuedElements_) {
        sendElement(stanza);
    }
    queuedElements_.clear();
}

void OutgoingLinkLocalSession::handleElement(std::shared_ptr<ToplevelElement> element) {
    onElementReceived(element);
}

void OutgoingLinkLocalSession::queueElement(std::shared_ptr<ToplevelElement> element) {
    queuedElements_.push_back(element);
}


}
