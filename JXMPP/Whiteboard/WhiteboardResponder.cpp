/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Whiteboard/WhiteboardResponder.h>

#include <memory>

#include <JXMPP/Queries/IQRouter.h>
#include <JXMPP/Whiteboard/IncomingWhiteboardSession.h>
#include <JXMPP/Whiteboard/WhiteboardSession.h>
#include <JXMPP/Whiteboard/WhiteboardSessionManager.h>

namespace JXMPP {
    WhiteboardResponder::WhiteboardResponder(WhiteboardSessionManager* sessionManager, IQRouter* router) : SetResponder<WhiteboardPayload>(router), sessionManager_(sessionManager), router_(router) {
    }

    bool WhiteboardResponder::handleSetRequest(const JID& from, const JID& /*to*/, const std::string& id, std::shared_ptr<WhiteboardPayload> payload) {
        if (payload->getType() == WhiteboardPayload::SessionRequest) {
            if (sessionManager_->getSession(from)) {
                sendError(from, id, ErrorPayload::Conflict, ErrorPayload::Cancel);
            } else {
                sendResponse(from, id, std::shared_ptr<WhiteboardPayload>());
                IncomingWhiteboardSession::ref session = std::make_shared<IncomingWhiteboardSession>(from, router_);
                sessionManager_->handleIncomingSession(session);
            }
        } else {
            sendResponse(from, id, std::shared_ptr<WhiteboardPayload>());
            WhiteboardSession::ref session = sessionManager_->getSession(from);
            if (session != nullptr) {
                session->handleIncomingAction(payload);
            }
        }
        return true;
    }
}
