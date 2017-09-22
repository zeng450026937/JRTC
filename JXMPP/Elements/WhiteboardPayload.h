#ifndef JXMPP_WHITEBOARDPAYLOAD_H
#define JXMPP_WHITEBOARDPAYLOAD_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardElement.h>
#include <JXMPP/Elements/Whiteboard/WhiteboardOperation.h>

namespace JXMPP {
    class JXMPP_API WhiteboardPayload : public Payload {
    public:
        typedef std::shared_ptr<WhiteboardPayload> ref;

    public:
        enum Type {UnknownType, Data, SessionRequest, SessionAccept, SessionTerminate};

        WhiteboardPayload(Type type = WhiteboardPayload::Data) : type_(type) {
        }

        void setData(const std::string &data) {
            data_ = data;
        }

        std::string getData() const {
            return data_;
        }

        Type getType() const {
            return type_;
        }

        void setType(Type type) {
            type_ = type;
        }

        WhiteboardElement::ref getElement() const {
            return element_;
        }

        void setElement(WhiteboardElement::ref element) {
            element_ = element;
        }

        WhiteboardOperation::ref getOperation() const {
            return operation_;
        }

        void setOperation(WhiteboardOperation::ref operation) {
            operation_ = operation;
        }

    private:
        std::string data_;
        Type type_;
        WhiteboardElement::ref element_;
        WhiteboardOperation::ref operation_;
    };
}

#endif // JXMPP_WHITEBOARDPAYLOAD_H
