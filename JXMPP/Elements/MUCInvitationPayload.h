#ifndef JXMPP_MUCINVITATIONPAYLOAD_H
#define JXMPP_MUCINVITATIONPAYLOAD_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API MUCInvitationPayload : public Payload {
        public:
            typedef std::shared_ptr<MUCInvitationPayload> ref;
            MUCInvitationPayload() : continuation_(false), impromptu_(false) {
            }

            void setIsContinuation(bool b) {
                continuation_ = b;
            }

            bool getIsContinuation() const {
                return continuation_;
            }

            void setIsImpromptu(bool b) {
                impromptu_ = b;
            }

            bool getIsImpromptu() const {
                return impromptu_;
            }

            void setJID(const JID& jid) {
                jid_ = jid;
            }

            const JID& getJID() const {
                return jid_;
            }

            void setPassword(const std::string& password) {
                password_ = password;
            }

            const std::string& getPassword() const {
                return password_;
            }

            void setReason(const std::string& text) {
                reason_ = text;
            }

            const std::string& getReason() const {
                return reason_;
            }

            void setThread(const std::string& thread) {
                thread_ = thread;
            }

            const std::string& getThread() const {
                return thread_;
            }

        private:
            bool continuation_;
            bool impromptu_;
            JID jid_;
            std::string password_;
            std::string reason_;
            std::string thread_;
    };
}

#endif // JXMPP_MUCINVITATIONPAYLOAD_H
