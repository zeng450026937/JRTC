#include <JXMPP/LinkLocal/IncomingLinkLocalSession.h>

#include <memory>

#include <boost/bind.hpp>

#include <JXMPP/Elements/IQ.h>
#include <JXMPP/Elements/ProtocolHeader.h>
#include <JXMPP/Elements/StreamFeatures.h>
#include <JXMPP/Network/Connection.h>
#include <JXMPP/StreamStack/ConnectionLayer.h>
#include <JXMPP/StreamStack/StreamStack.h>
#include <JXMPP/StreamStack/XMPPLayer.h>

namespace JXMPP {

IncomingLinkLocalSession::IncomingLinkLocalSession(
        const JID& localJID,
        std::shared_ptr<Connection> connection,
        PayloadParserFactoryCollection* payloadParserFactories,
        PayloadSerializerCollection* payloadSerializers,
        XMLParserFactory* xmlParserFactory) :
            Session(connection, payloadParserFactories, payloadSerializers, xmlParserFactory),
            initialized(false) {
    setLocalJID(localJID);
}

void IncomingLinkLocalSession::handleStreamStart(const ProtocolHeader& incomingHeader) {
    setRemoteJID(JID(incomingHeader.getFrom()));
    if (!getRemoteJID().isValid()) {
        finishSession();
        return;
    }

    ProtocolHeader header;
    header.setFrom(getLocalJID());
    getXMPPLayer()->writeHeader(header);

    if (incomingHeader.getVersion() == "1.0") {
        getXMPPLayer()->writeElement(std::make_shared<StreamFeatures>());
    }
    else {
        setInitialized();
    }
}

void IncomingLinkLocalSession::handleElement(std::shared_ptr<ToplevelElement> element) {
    std::shared_ptr<Stanza> stanza = std::dynamic_pointer_cast<Stanza>(element);
    // If we get our first stanza before streamfeatures, our session is implicitly
    // initialized
    if (stanza && !isInitialized()) {
        setInitialized();
    }

    onElementReceived(element);
}

void IncomingLinkLocalSession::setInitialized() {
    initialized = true;
    onSessionStarted();
}



}
