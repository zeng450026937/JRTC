#ifndef JXMPP_PAYLOADADDINGPRESENCESENDER_H
#define JXMPP_PAYLOADADDINGPRESENCESENDER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Presence/PresenceSender.h>

namespace JXMPP {
    /**
     * This presence sender adds payloads to outgoing presences.
     *
     * This class isn't meant to be used with directed presence.
     */
    class JXMPP_API PayloadAddingPresenceSender : public PresenceSender {
        public:
            PayloadAddingPresenceSender(PresenceSender*);

            void sendPresence(std::shared_ptr<Presence>);
            bool isAvailable() const;

            /**
             * Sets the payload to be added to outgoing presences.
             * If initial presence has been sent, this will resend the last sent presence
             * with an updated payload. Initial presence is reset when unavailable presence is
             * sent, or when reset() is called.
             */
            void setPayload(std::shared_ptr<Payload>);

             /**
              * Resets the presence sender.
              * This puts the presence sender back in the initial state (before initial
              * presence has been sent).
              * This also resets the chained sender.
              */
             void reset();

        private:
            std::shared_ptr<Presence> lastSentPresence;
            PresenceSender* sender;
            std::shared_ptr<Payload> payload;
    };
}

#endif // JXMPP_PAYLOADADDINGPRESENCESENDER_H
