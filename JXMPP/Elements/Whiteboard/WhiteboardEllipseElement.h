#ifndef JXMPP_WHITEBOARDELLIPSEELEMENT_H
#define JXMPP_WHITEBOARDELLIPSEELEMENT_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardColor.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>

namespace JXMPP {
    class JXMPP_API WhiteboardEllipseElement : public WhiteboardElement {
    public:
        typedef std::shared_ptr<WhiteboardEllipseElement> ref;
    public:
        WhiteboardEllipseElement(int cx, int cy, int rx, int ry) {
            cx_ = cx;
            cy_ = cy;
            rx_ = rx;
            ry_ = ry;
        }

        int getCX() const {
            return cx_;
        }

        int getCY() const {
            return cy_;
        }

        int getRX() const {
            return rx_;
        }

        int getRY() const {
            return ry_;
        }

        const WhiteboardColor& getPenColor() const {
            return penColor_;
        }

        void setPenColor(const WhiteboardColor& color) {
            penColor_ = color;
        }

        const WhiteboardColor& getBrushColor() const {
            return brushColor_;
        }

        void setBrushColor(const WhiteboardColor& color) {
            brushColor_ = color;
        }

        int getPenWidth() const {
            return penWidth_;
        }

        void setPenWidth(const int penWidth) {
            penWidth_ = penWidth;
        }

        void accept(WhiteboardElementVisitor& visitor) {
            visitor.visit(*this);
        }

    private:
        int cx_, cy_, rx_, ry_;
        WhiteboardColor penColor_;
        WhiteboardColor brushColor_;
        int penWidth_ = 0;
    };
}

#endif // JXMPP_WHITEBOARDELLIPSEELEMENT_H
