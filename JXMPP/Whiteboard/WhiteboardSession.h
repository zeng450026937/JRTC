#ifndef JXMPP_WHITEBOARDSESSION_H
#define JXMPP_WHITEBOARDSESSION_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/IDGenerator.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardOperation.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Queries/GenericRequest.h>

namespace JXMPP {
    class IQRouter;
    class WhiteboardPayload;

    class JXMPP_API WhiteboardSession {
    public:
        typedef std::shared_ptr<WhiteboardSession> ref;

    public:
        WhiteboardSession(const JID& jid, IQRouter* router);
        virtual ~WhiteboardSession();
        void handleIncomingAction(std::shared_ptr<WhiteboardPayload> payload);
        void sendElement(const WhiteboardElement::ref element);
        virtual void sendOperation(WhiteboardOperation::ref operation) = 0;
        void cancel();
        const JID& getTo() const;

    public:
        boost::signals2::signal< void(const WhiteboardElement::ref element)> onElementReceived;
        boost::signals2::signal< void(const WhiteboardOperation::ref operation)> onOperationReceived;
        boost::signals2::signal< void(const JID& contact)> onSessionTerminated;
        boost::signals2::signal< void(const JID& contact)> onRequestAccepted;
        boost::signals2::signal< void(const JID& contact)> onRequestRejected;

    private:
        virtual void handleIncomingOperation(WhiteboardOperation::ref operation) = 0;

    protected:
        void sendPayload(std::shared_ptr<WhiteboardPayload> payload);

        JID toJID_;
        IQRouter* router_;
        std::string lastOpID;
        IDGenerator idGenerator;
    };
}

#endif // JXMPP_WHITEBOARDSESSION_H
