#ifndef JXMPP_WHITEBOARDELEMENT_H
#define JXMPP_WHITEBOARDELEMENT_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>
#include <string>

#include <JXMPP/Elements/Whiteboard/WhiteboardElementVisitor.h>

namespace JXMPP {
    class WhiteboardElement {
    public:
        typedef std::shared_ptr<WhiteboardElement> ref;

    public:
        virtual ~WhiteboardElement() {}
        virtual void accept(WhiteboardElementVisitor& visitor) = 0;

        const std::string& getID() const {
            return id_;
        }

        void setID(const std::string& id) {
            id_ = id;
        }

    private:
        std::string id_;
    };
}

#endif // JXMPP_WHITEBOARDELEMENT_H
