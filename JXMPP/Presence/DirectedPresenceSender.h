#ifndef JXMPP_DIRECTEDPRESENCESENDER_H
#define JXMPP_DIRECTEDPRESENCESENDER_H

#include <set>

#include <boost/optional.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Presence.h>
#include <JXMPP/Presence/PresenceSender.h>

namespace JXMPP {
    class JXMPP_API DirectedPresenceSender : public PresenceSender {
        public:
            enum SendPresence {AndSendPresence, DontSendPresence};
            DirectedPresenceSender(PresenceSender*);

            void addDirectedPresenceReceiver(const JID&, SendPresence);
            void removeDirectedPresenceReceiver(const JID&, SendPresence);

            void sendPresence(Presence::ref);

            boost::optional<Presence::ref> getLastSentUndirectedPresence() const;

            bool isAvailable() const;

        private:
            boost::optional<Presence::ref> lastSentUndirectedPresence;
            PresenceSender* sender;
            std::set<JID> directedPresenceReceivers;
    };
}

#endif // JXMPP_DIRECTEDPRESENCESENDER_H
