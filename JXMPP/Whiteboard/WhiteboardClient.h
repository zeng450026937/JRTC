#ifndef JXMPP_WHITEBOARDCLIENT_H
#define JXMPP_WHITEBOARDCLIENT_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <list>
#include <utility>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardOperation.h>

namespace JXMPP {
    class JXMPP_API WhiteboardClient {
    public:
        struct Result {
            WhiteboardOperation::ref client;
            WhiteboardOperation::ref server;
        };
        /*!
         * @return Operation to send
         */
        WhiteboardOperation::ref handleLocalOperationReceived(WhiteboardOperation::ref operation);
        /*!
         * @return pair.first-element to handle locally, pair.second-element to send to server
         */
        Result handleServerOperationReceived(WhiteboardOperation::ref operation);
        void print();

    private:
        std::list<WhiteboardOperation::ref> localOperations_;
        std::list<WhiteboardOperation::ref> serverOperations_;
        std::list<WhiteboardOperation::ref> bridge_;
        std::string lastSentOperationID_;
    };
}

#endif // JXMPP_WHITEBOARDCLIENT_H
