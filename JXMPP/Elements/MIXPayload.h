#ifndef JXMPP_MIXPAYLOAD_H
#define JXMPP_MIXPAYLOAD_H

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
    class JXMPP_API MIXPayload : public Payload {
        public:
            using ref = std::shared_ptr<MIXPayload>;

        public:

            MIXPayload() {}

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

            const boost::optional<std::string>& getSubmissionID() const {
                return submissionId_;
            }

            void setSubmissionID(const std::string& submissionId) {
                submissionId_ = submissionId;
            }

        private:
            boost::optional<JID> jid_;
            boost::optional<std::string> nick_;
            boost::optional<std::string> submissionId_;
    };
}

#endif // JXMPP_MIXPAYLOAD_H
