#ifndef JXMPP_REPLACE_H
#define JXMPP_REPLACE_H

/*
 * Copyright (c) 2011 Vlad Voicu
 * Licensed under the Simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API Replace : public Payload {
        public:
            typedef std::shared_ptr<Replace> ref;
            Replace(const std::string& id = std::string()) : replaceID_(id) {}
            const std::string& getID() const {
                return replaceID_;
            }
            void setID(const std::string& id) {
                replaceID_ = id;
            }
        private:
            std::string replaceID_;
    };
}

#endif // JXMPP_REPLACE_H
