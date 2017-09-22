#ifndef JXMPP_OUTGOINGWHITEBOARDSESSION_H
#define JXMPP_OUTGOINGWHITEBOARDSESSION_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Queries/GenericRequest.h>
#include <JXMPP/Whiteboard/WhiteboardServer.h>
#include <JXMPP/Whiteboard/WhiteboardSession.h>

namespace JXMPP {
    class JXMPP_API OutgoingWhiteboardSession : public WhiteboardSession {
    public:
        typedef std::shared_ptr<OutgoingWhiteboardSession> ref;

    public:
        OutgoingWhiteboardSession(const JID& jid, IQRouter* router);
        virtual ~OutgoingWhiteboardSession();
        void startSession();

    private:
        void handleRequestResponse(std::shared_ptr<WhiteboardPayload> /*payload*/, ErrorPayload::ref error);
        void handleIncomingOperation(WhiteboardOperation::ref operation);
        void sendOperation(WhiteboardOperation::ref operation);

        WhiteboardServer server;
    };
}

#endif // JXMPP_OUTGOINGWHITEBOARDSESSION_H
