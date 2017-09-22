#ifndef JXMPP_MIXREGISTERNICK_H
#define JXMPP_MIXREGISTERNICK_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <memory>
#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API MIXRegisterNick : public Payload {
        public:
            using ref = std::shared_ptr<MIXRegisterNick>;

        public:

            MIXRegisterNick() {}

            const std::string& getNick() const {
                return nick_;
            }

            void setNick(const std::string& nick) {
                nick_ = nick;
            }

        private:
            std::string nick_;
    };
}

#endif // JXMPP_MIXREGISTERNICK_H
