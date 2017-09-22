#ifndef JXMPP_ENTITYCAPSMANAGER_H
#define JXMPP_ENTITYCAPSMANAGER_H

#include <map>

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Base/LRUCache.h>
#include <JXMPP/Disco/EntityCapsProvider.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Elements/ErrorPayload.h>
#include <JXMPP/Elements/Presence.h>

namespace JXMPP {
    class StanzaChannel;
    class CapsProvider;

    /**
     * This class is responsible for gathering and providing
     * information about capabilities of entities on the network.
     * This information is provided in the form of service discovery
     * information.
     */
    class JXMPP_API EntityCapsManager : public EntityCapsProvider, public boost::signals2::trackable {
        public:
            EntityCapsManager(CapsProvider*, StanzaChannel*);

            /**
             * Returns the service discovery information of the given JID.
             */
            DiscoInfo::ref getCaps(const JID&) const;

            DiscoInfo::ref getCapsCached(const JID&);

        private:
            void handlePresenceReceived(std::shared_ptr<Presence>);
            void handleStanzaChannelAvailableChanged(bool);
            void handleCapsAvailable(const std::string&);

        private:
            CapsProvider* capsProvider;
            std::map<JID, std::string> caps;
            LRUCache<std::string, DiscoInfo::ref, 64> lruDiscoCache;
    };
}

#endif // JXMPP_ENTITYCAPSMANAGER_H
