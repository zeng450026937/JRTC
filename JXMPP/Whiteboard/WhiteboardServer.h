#ifndef JXMPP_WHITEBOARDSERVER_H
#define JXMPP_WHITEBOARDSERVER_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <list>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardInsertOperation.h>

namespace JXMPP {
    class JXMPP_API WhiteboardServer {
    public:
        void handleLocalOperationReceived(WhiteboardOperation::ref operation);
        WhiteboardOperation::ref handleClientOperationReceived(WhiteboardOperation::ref operation);
        void print();

    private:
        std::list<WhiteboardOperation::ref> operations_;
    };
}

#endif // JXMPP_WHITEBOARDSERVER_H
