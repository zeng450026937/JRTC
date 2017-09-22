#ifndef JXMPP_WHITEBOARDTRANSFORMER_H
#define JXMPP_WHITEBOARDTRANSFORMER_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <utility>

#include <JXMPP/Elements/Whiteboard/WhiteboardDeleteOperation.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardInsertOperation.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardUpdateOperation.h>

namespace JXMPP {
    class WhiteboardTransformer {
    public:
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardOperation::ref clientOp, WhiteboardOperation::ref serverOp);
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardInsertOperation::ref clientOp, WhiteboardInsertOperation::ref serverOp);
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardUpdateOperation::ref clientOp, WhiteboardUpdateOperation::ref serverOp);
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardUpdateOperation::ref clientOp, WhiteboardInsertOperation::ref serverOp);
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardInsertOperation::ref clientOp, WhiteboardUpdateOperation::ref serverOp);
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardDeleteOperation::ref clientOp, WhiteboardDeleteOperation::ref serverOp);
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardInsertOperation::ref clientOp, WhiteboardDeleteOperation::ref serverOp);
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardDeleteOperation::ref clientOp, WhiteboardInsertOperation::ref serverOp);
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardUpdateOperation::ref clientOp, WhiteboardDeleteOperation::ref serverOp);
        static std::pair<WhiteboardOperation::ref, WhiteboardOperation::ref> transform(WhiteboardDeleteOperation::ref clientOp, WhiteboardUpdateOperation::ref serverOp);
    };
}

#endif // JXMPP_WHITEBOARDTRANSFORMER_H
