#ifndef JXMPP_WHITEBOARDPOLYGONELEMENT_H
#define JXMPP_WHITEBOARDPOLYGONELEMENT_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <vector>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardColor.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>

namespace JXMPP {
    class JXMPP_API WhiteboardPolygonElement : public WhiteboardElement {
        typedef std::pair<int, int> Point;
    public:
        typedef std::shared_ptr<WhiteboardPolygonElement> ref;
    public:
        WhiteboardPolygonElement() {
        }

        const std::vector<Point>& getPoints() const {
            return points_;
        }

        void setPoints(const std::vector<Point>& points) {
            points_ = points;
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
        std::vector<Point> points_;
        WhiteboardColor penColor_;
        WhiteboardColor brushColor_;
        int penWidth_ = 0;
    };
}

#endif // JXMPP_WHITEBOARDPOLYGONELEMENT_H
