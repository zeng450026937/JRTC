#ifndef JXMPP_INCOMINGWHITEBOARDSESSION_H
#define JXMPP_INCOMINGWHITEBOARDSESSION_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Whiteboard/WhiteboardClient.h>
#include <JXMPP/Whiteboard/WhiteboardSession.h>

namespace JXMPP {
    class JXMPP_API IncomingWhiteboardSession : public WhiteboardSession {
    public:
        typedef std::shared_ptr<IncomingWhiteboardSession> ref;

    public:
        IncomingWhiteboardSession(const JID& jid, IQRouter* router);
        ~IncomingWhiteboardSession();

        void accept();

    private:
        void handleIncomingOperation(WhiteboardOperation::ref operation);
        void sendOperation(WhiteboardOperation::ref operation);

        WhiteboardClient client;
    };
}

#endif // JXMPP_INCOMINGWHITEBOARDSESSION_H
