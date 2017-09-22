#ifndef JXMPP_MUCDESTROYPAYLOAD_H
#define JXMPP_MUCDESTROYPAYLOAD_H

#include <string>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API MUCDestroyPayload : public Payload {
        public:
            typedef std::shared_ptr<MUCDestroyPayload> ref;

            MUCDestroyPayload() {
            }

            void setNewVenue(const JID& jid) {
                newVenue_ = jid;
            }

            const JID& getNewVenue() const {
                return newVenue_;
            }

            void setReason(const std::string& reason) {
                reason_ = reason;
            }

            const std::string& getReason() const {
                return reason_;
            }

        private:
            JID newVenue_;
            std::string reason_;
    };
}

#endif // JXMPP_MUCDESTROYPAYLOAD_H
