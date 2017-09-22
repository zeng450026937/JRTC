#ifndef JXMPP_WHITEBOARDPARSER_H
#define JXMPP_WHITEBOARDPARSER_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardOperation.h>
#include <JXMPP/Elements/WhiteboardPayload.h>
#include <JXMPP/Parser/GenericPayloadParser.h>

namespace JXMPP {
    class JXMPP_API WhiteboardParser : public JXMPP::GenericPayloadParser<WhiteboardPayload> {
    public:
        WhiteboardParser();

        virtual void handleStartElement(const std::string& element, const std::string&, const AttributeMap& attributes);
        virtual void handleEndElement(const std::string& element, const std::string&);
        virtual void handleCharacterData(const std::string& data);

    private:
        WhiteboardPayload::Type stringToType(const std::string& type) const;
        int opacityToAlpha(std::string opacity) const;

    private:
        bool actualIsText;
        int level_;
        std::string data_;
        WhiteboardElement::ref wbElement;
        WhiteboardOperation::ref operation;
    };
}

#endif // JXMPP_WHITEBOARDPARSER_H
