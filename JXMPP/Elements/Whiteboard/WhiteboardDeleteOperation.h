#ifndef JXMPP_WHITEBOARDDELETEOPERATION_H
#define JXMPP_WHITEBOARDDELETEOPERATION_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardOperation.h>

namespace JXMPP {
    class JXMPP_API WhiteboardDeleteOperation : public WhiteboardOperation {
    public:
        typedef std::shared_ptr<WhiteboardDeleteOperation> ref;
    public:
        std::string getElementID() const {
            return elementID_;
        }

        void setElementID(const std::string& elementID) {
            elementID_ = elementID;
        }

    private:
        std::string elementID_;
    };
}

#endif // JXMPP_WHITEBOARDDELETEOPERATION_H
