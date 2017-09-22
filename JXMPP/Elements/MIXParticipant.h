#ifndef JXMPP_MIXPARTICIPANT_H
#define JXMPP_MIXPARTICIPANT_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <memory>
#include <string>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API MIXParticipant : public Payload {
        public:
            using ref = std::shared_ptr<MIXParticipant>;

        public:

            MIXParticipant() {}

            const boost::optional<std::string>& getNick() const {
                return nick_;
            }

            void setNick(const std::string& nick) {
                nick_ = nick;
            }

            const boost::optional<JID>& getJID() const {
                return jid_;
            }

            void setJID(const JID& jid) {
                jid_ = jid;
            }

        private:
            boost::optional<JID> jid_;
            boost::optional<std::string> nick_;
    };
}

#endif // JXMPP_MIXPARTICIPANT_H
