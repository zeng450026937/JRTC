#ifndef JXMPP_WHITEBOARDINSERTOPERATION_H
#define JXMPP_WHITEBOARDINSERTOPERATION_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardOperation.h>

namespace JXMPP {
    class JXMPP_API WhiteboardInsertOperation : public WhiteboardOperation {
    public:
        typedef std::shared_ptr<WhiteboardInsertOperation> ref;
    public:
        WhiteboardElement::ref getElement() const {
            return element_;
        }

        void setElement(WhiteboardElement::ref element) {
            element_ = element;
        }

    private:
        WhiteboardElement::ref element_;
    };
}

#endif // JXMPP_WHITEBOARDINSERTOPERATION_H
