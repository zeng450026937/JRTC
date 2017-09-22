#include <JXMPP/Jingle/JingleSessionManager.h>

#include <JXMPP/Base/Algorithm.h>
#include <JXMPP/Base/Log.h>
#include <JXMPP/Jingle/IncomingJingleSessionHandler.h>
#include <JXMPP/Jingle/JingleResponder.h>

namespace JXMPP {

JingleSessionManager::JingleSessionManager(IQRouter* router) : router(router) {
    responder = new JingleResponder(this, router);
    responder->start();
}

JingleSessionManager::~JingleSessionManager() {
    responder->stop();
    delete responder;
}

JingleSessionImpl::ref JingleSessionManager::getSession(const JID& jid, const std::string& id) const {
    SessionMap::const_iterator i = sessions.find(JIDSession(jid, id));
    return i != sessions.end() ? i->second : JingleSessionImpl::ref();
}

void JingleSessionManager::addIncomingSessionHandler(IncomingJingleSessionHandler* handler) {
    incomingSessionHandlers.push_back(handler);
}

void JingleSessionManager::removeIncomingSessionHandler(IncomingJingleSessionHandler* handler) {
    erase(incomingSessionHandlers, handler);
}

void JingleSessionManager::registerOutgoingSession(const JID& initiator, JingleSessionImpl::ref session) {
    sessions.insert(std::make_pair(JIDSession(initiator, session->getID()), session));
    JXMPP_LOG(debug) << "Added session " << session->getID() << " for initiator " << initiator.toString() << std::endl;
}

void JingleSessionManager::handleIncomingSession(const JID& initiator, const JID& recipient, JingleSessionImpl::ref session, const std::vector<JingleContentPayload::ref>& contents) {
    sessions.insert(std::make_pair(JIDSession(initiator, session->getID()), session));
    for (auto handler : incomingSessionHandlers) {
        if (handler->handleIncomingJingleSession(session, contents, recipient)) {
            return;
        }
    }
    // TODO: Finish session
}


}
