#ifndef JXMPP_STANZACHANNELPRESENCESENDER_H
#define JXMPP_STANZACHANNELPRESENCESENDER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Presence/PresenceSender.h>

namespace JXMPP {
    class StanzaChannel;

    class JXMPP_API StanzaChannelPresenceSender : public PresenceSender {
        public:
            StanzaChannelPresenceSender(StanzaChannel*);

            void sendPresence(Presence::ref);

            bool isAvailable() const;

        private:
            StanzaChannel* channel;
    };
}

#endif // JXMPP_STANZACHANNELPRESENCESENDER_H
