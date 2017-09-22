#ifndef JXMPP_WHITEBOARDUPDATEOPERATION_H
#define JXMPP_WHITEBOARDUPDATEOPERATION_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardOperation.h>

namespace JXMPP {
    class JXMPP_API WhiteboardUpdateOperation : public WhiteboardOperation {
    public:
        typedef std::shared_ptr<WhiteboardUpdateOperation> ref;
    public:
        WhiteboardElement::ref getElement() const {
            return element_;
        }

        void setElement(WhiteboardElement::ref element) {
            element_ = element;
        }

        int getNewPos() const {
            return newPos_;
        }

        void setNewPos(int newPos) {
            newPos_ = newPos;
        }

    private:
        WhiteboardElement::ref element_;
        int newPos_ = 0;
    };
}

#endif // JXMPP_WHITEBOARDUPDATEOPERATION_H
