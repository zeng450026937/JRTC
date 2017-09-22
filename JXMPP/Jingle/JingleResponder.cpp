#include <JXMPP/Jingle/JingleResponder.h>

#include <memory>

#include <JXMPP/Base/Log.h>
#include <JXMPP/Jingle/JingleSessionImpl.h>
#include <JXMPP/Jingle/JingleSessionManager.h>

namespace JXMPP {

JingleResponder::JingleResponder(JingleSessionManager* sessionManager, IQRouter* router) : SetResponder<JinglePayload>(router), sessionManager(sessionManager), router(router) {
}

JingleResponder::~JingleResponder() {
}

bool JingleResponder::handleSetRequest(const JID& from, const JID& to, const std::string& id, std::shared_ptr<JinglePayload> payload) {
    if (payload->getAction() == JinglePayload::SessionInitiate) {
        if (sessionManager->getSession(from, payload->getSessionID())) {
            // TODO: Add tie-break error
            sendError(from, id, ErrorPayload::Conflict, ErrorPayload::Cancel);
        }
        else {
            sendResponse(from, id, std::shared_ptr<JinglePayload>());
            if (!payload->getInitiator().isBare()) {
                JingleSessionImpl::ref session = std::make_shared<JingleSessionImpl>(payload->getInitiator(), from, payload->getSessionID(), router);
                sessionManager->handleIncomingSession(from, to, session, payload->getContents());
            } else {
                JXMPP_LOG(debug) << "Unable to create Jingle session due to initiator not being a full JID." << std::endl;
            }
        }
    }
    else {
        JingleSessionImpl::ref session;
        if (payload->getInitiator().isValid()) {
            JXMPP_LOG(debug) << "Lookup session by initiator." << std::endl;
            session = sessionManager->getSession(payload->getInitiator(), payload->getSessionID());
        } else {
            JXMPP_LOG(debug) << "Lookup session by from attribute." << std::endl;
            session = sessionManager->getSession(from, payload->getSessionID());
        }
        if (session) {
            session->handleIncomingAction(payload);
            sendResponse(from, id, std::shared_ptr<JinglePayload>());
        }
        else {
            JXMPP_LOG(warning) << "Didn't find jingle session!";
            // TODO: Add jingle-specific error
            sendError(from, id, ErrorPayload::ItemNotFound, ErrorPayload::Cancel);
        }
    }
    return true;
}

}
