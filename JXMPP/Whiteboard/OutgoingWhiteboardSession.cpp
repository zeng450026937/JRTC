/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */


#include <JXMPP/Whiteboard/OutgoingWhiteboardSession.h>

#include <memory>

#include <boost/bind.hpp>

#include <JXMPP/Elements/Whiteboard/WhiteboardDeleteOperation.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardInsertOperation.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardUpdateOperation.h>
#include <JXMPP/Elements/WhiteboardPayload.h>

namespace JXMPP {
    OutgoingWhiteboardSession::OutgoingWhiteboardSession(const JID& jid, IQRouter* router) : WhiteboardSession(jid, router) {
    }

    OutgoingWhiteboardSession::~OutgoingWhiteboardSession() {
    }

    void OutgoingWhiteboardSession::startSession() {
        std::shared_ptr<WhiteboardPayload> payload = std::make_shared<WhiteboardPayload>(WhiteboardPayload::SessionRequest);
        std::shared_ptr<GenericRequest<WhiteboardPayload> > request = std::make_shared<GenericRequest<WhiteboardPayload> >(IQ::Set, toJID_, payload, router_);
        request->onResponse.connect(boost::bind(&OutgoingWhiteboardSession::handleRequestResponse, this, _1, _2));
        request->send();
    }

    void OutgoingWhiteboardSession::handleRequestResponse(std::shared_ptr<WhiteboardPayload> /*payload*/, ErrorPayload::ref error) {
        if (error) {
            onRequestRejected(toJID_);
        }
    }

    void OutgoingWhiteboardSession::handleIncomingOperation(WhiteboardOperation::ref operation) {
        WhiteboardOperation::ref op = server.handleClientOperationReceived(operation);
        if (op->getPos() != -1) {
            onOperationReceived(op);
        }
        lastOpID = op->getID();

        WhiteboardPayload::ref payload = std::make_shared<WhiteboardPayload>();
        payload->setOperation(op);
        sendPayload(payload);
    }

    void OutgoingWhiteboardSession::sendOperation(WhiteboardOperation::ref operation) {
        operation->setID(idGenerator.generateID());
        operation->setParentID(lastOpID);
        lastOpID = operation->getID();

        server.handleLocalOperationReceived(operation);
        WhiteboardPayload::ref payload = std::make_shared<WhiteboardPayload>();
        payload->setOperation(operation);
        sendPayload(payload);
    }
}
