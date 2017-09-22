#ifndef JXMPP_ENTITYCAPSPROVIDER_H
#define JXMPP_ENTITYCAPSPROVIDER_H

#include <boost/signals2.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    /**
     * This class provides information about capabilities of entities on the network.
     * This information is provided in the form of service discovery
     * information.
     */
    class JXMPP_API EntityCapsProvider {
        public:
            virtual ~EntityCapsProvider();

            /**
             * Returns the service discovery information of the given JID.
             */
            virtual DiscoInfo::ref getCaps(const JID&) const = 0;

            virtual DiscoInfo::ref getCapsCached(const JID&) = 0;

            /**
             * Emitted when the capabilities of a JID changes.
             */
            boost::signals2::signal<void (const JID&)> onCapsChanged;
    };
}

#endif // JXMPP_ENTITYCAPSPROVIDER_H
