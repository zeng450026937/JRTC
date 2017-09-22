#ifndef JXMPP_WHITEBOARDSESSIONMANAGER_H
#define JXMPP_WHITEBOARDSESSIONMANAGER_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <map>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Client/StanzaChannel.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Queries/IQRouter.h>
#include <JXMPP/Whiteboard/IncomingWhiteboardSession.h>
#include <JXMPP/Whiteboard/OutgoingWhiteboardSession.h>
#include <JXMPP/Whiteboard/WhiteboardSession.h>

namespace JXMPP {
    class IQRouter;
    class WhiteboardResponder;
    class PresenceOracle;
    class EntityCapsProvider;

    class JXMPP_API WhiteboardSessionManager {
        friend class WhiteboardResponder;
    public:
        WhiteboardSessionManager(IQRouter* router, StanzaChannel* stanzaChannel, PresenceOracle* presenceOracle, EntityCapsProvider* capsProvider);
        ~WhiteboardSessionManager();

        WhiteboardSession::ref getSession(const JID& to);
        WhiteboardSession::ref requestSession(const JID& to);

    public:
        boost::signals2::signal< void (IncomingWhiteboardSession::ref)> onSessionRequest;

    private:
        JID getFullJID(const JID& bareJID);
        OutgoingWhiteboardSession::ref createOutgoingSession(const JID& to);
        void handleIncomingSession(IncomingWhiteboardSession::ref session);
        void handlePresenceReceived(Presence::ref presence);
        void handleAvailableChanged(bool available);
        void deleteSessionEntry(const JID& contact);

    private:
        std::map<JID, std::shared_ptr<WhiteboardSession> > sessions_;
        IQRouter* router_;
        StanzaChannel* stanzaChannel_;
        PresenceOracle* presenceOracle_;
        EntityCapsProvider* capsProvider_;
        WhiteboardResponder* responder;
    };
}

#endif // JXMPP_WHITEBOARDSESSIONMANAGER_H
