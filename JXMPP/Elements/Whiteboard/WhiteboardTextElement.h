#ifndef JXMPP_WHITEBOARDTEXTELEMENT_H
#define JXMPP_WHITEBOARDTEXTELEMENT_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardColor.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>

namespace JXMPP {
    class JXMPP_API WhiteboardTextElement : public WhiteboardElement {
    public:
        typedef std::shared_ptr<WhiteboardTextElement> ref;
    public:
        WhiteboardTextElement(int x, int y) {
            x_ = x;
            y_ = y;
        }

        void setText(const std::string text) {
            text_ = text;
        }

        const std::string& getText() const {
            return text_;
        }

        int getX() const {
            return x_;
        }

        int getY() const {
            return y_;
        }

        const WhiteboardColor& getColor() const {
            return color_;
        }

        void setColor(const WhiteboardColor& color) {
            color_ = color;
        }

        int getSize() const {
            return size_;
        }

        void setSize(const int size) {
            size_ = size;
        }

        void accept(WhiteboardElementVisitor& visitor) {
            visitor.visit(*this);
        }

    private:
        int x_, y_;
        int size_ = 0;
        std::string text_;
        WhiteboardColor color_;
    };
}

#endif // JXMPP_WHITEBOARDTEXTELEMENT_H
