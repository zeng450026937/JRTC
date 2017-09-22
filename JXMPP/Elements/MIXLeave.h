#ifndef JXMPP_MIXLEAVE_H
#define JXMPP_MIXLEAVE_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <memory>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>
#include <JXMPP/Elements/Payload.h>

namespace JXMPP {
    class JXMPP_API MIXLeave : public Payload {
        public:
            using ref = std::shared_ptr<MIXLeave>;

        public:

            MIXLeave() {}

            const boost::optional<JID>& getChannel() const {
                return channel_;
            }

            void setChannel(const JID& channel) {
                channel_ = channel;
            }

        private:
            boost::optional<JID> channel_;
    };
}

#endif // JXMPP_MIXLEAVE_H
