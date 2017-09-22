#ifndef JXMPP_WHITEBOARDOPERATION_H
#define JXMPP_WHITEBOARDOPERATION_H

/*
 * Copyright (c) 2012 Mateusz Piękos
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <string>

#include <boost/smart_ptr/shared_ptr.hpp>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class WhiteboardOperation {
    public:
        typedef std::shared_ptr<WhiteboardOperation> ref;
    public:
        WhiteboardOperation() {}
        JXMPP_DEFAULT_COPY_CONSTRUCTOR(WhiteboardOperation)
        virtual ~WhiteboardOperation(){}

        std::string getID() const {
            return id_;
        }

        void setID(const std::string& id) {
            id_ = id;
        }

        std::string getParentID() const {
            return parentID_;
        }

        void setParentID(const std::string& parentID) {
            parentID_ = parentID;
        }

        int getPos() const {
            return pos_;
        }

        void setPos(int pos) {
            pos_ = pos;
        }

    private:
        std::string id_;
        std::string parentID_;
        int pos_ = 0;
    };
}

#endif // JXMPP_WHITEBOARDOPERATION_H
