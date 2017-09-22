#ifndef JXMPP_WHITEBOARDRESPONDER_H
#define JXMPP_WHITEBOARDRESPONDER_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/WhiteboardPayload.h>
#include <JXMPP/Queries/SetResponder.h>

namespace JXMPP {
    class IQRouter;
    class WhiteboardSessionManager;

    class JXMPP_API WhiteboardResponder : public SetResponder<WhiteboardPayload> {
    public:
        WhiteboardResponder(WhiteboardSessionManager* sessionManager, IQRouter* router);
        bool handleSetRequest(const JID& from, const JID& /*to*/, const std::string& id, std::shared_ptr<WhiteboardPayload> payload);

    private:
        WhiteboardSessionManager* sessionManager_;
        IQRouter* router_;
    };
}

#endif // JXMPP_WHITEBOARDRESPONDER_H
