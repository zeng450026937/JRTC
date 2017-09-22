#ifndef JXMPP_WHITEBOARDFREEHANDPATHELEMENT_H
#define JXMPP_WHITEBOARDFREEHANDPATHELEMENT_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <utility>
#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardColor.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>

namespace JXMPP {
    class JXMPP_API WhiteboardFreehandPathElement : public WhiteboardElement {
        typedef std::pair<int, int> Point;
    public:
        typedef std::shared_ptr<WhiteboardFreehandPathElement> ref;
    public:
        WhiteboardFreehandPathElement() {
        }

        void setPoints(const std::vector<Point>& points) {
            points_ = points;
        }

        const std::vector<Point>& getPoints() const {
            return points_;
        }

        const WhiteboardColor& getColor() const {
            return color_;
        }

        void setColor(const WhiteboardColor& color) {
            color_ = color;
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
        std::vector<Point> points_;
        WhiteboardColor color_;
        int penWidth_ = 0;
    };
}

#endif // JXMPP_WHITEBOARDFREEHANDPATHELEMENT_H
