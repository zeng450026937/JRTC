#ifndef JXMPP_MIXDESTROY_H
#define JXMPP_MIXDESTROY_H

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
    class JXMPP_API MIXDestroy : public Payload {
        public:
            using ref = std::shared_ptr<MIXDestroy>;

        public:
            MIXDestroy() {}
            virtual ~MIXDestroy() {}

            const std::string& getChannel() const {
                return channel_;
            }

            void setChannel(const std::string& channel) {
                this->channel_ = channel;
            }

        private:
            std::string channel_;
    };
}

#endif // JXMPP_MIXDESTROY_H
