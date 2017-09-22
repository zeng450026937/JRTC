#ifndef JXMPP_WHITEBOARDSERIALIZER_H
#define JXMPP_WHITEBOARDSERIALIZER_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElementVisitor.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardEllipseElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardFreehandPathElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardLineElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardPolygonElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardRectElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardTextElement.h>
#include <JXMPP/Elements/WhiteboardPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API WhiteboardElementSerializingVisitor : public WhiteboardElementVisitor {
    public:
        void visit(WhiteboardLineElement& line);
        void visit(WhiteboardFreehandPathElement& path);
        void visit(WhiteboardRectElement& rect);
        void visit(WhiteboardPolygonElement& polygon);
        void visit(WhiteboardTextElement& text);
        void visit(WhiteboardEllipseElement& ellipse);
        XMLElement::ref getResult() const;

    private:
        std::string alphaToOpacity(int alpha) const;

        XMLElement::ref element;
    };

    class JXMPP_API WhiteboardSerializer : public GenericPayloadSerializer<WhiteboardPayload> {
    public:
        std::string serializePayload(std::shared_ptr<WhiteboardPayload> payload) const;

    private:
        std::string typeToString(WhiteboardPayload::Type type) const;
    };
}

#endif // JXMPP_WHITEBOARDSERIALIZER_H
