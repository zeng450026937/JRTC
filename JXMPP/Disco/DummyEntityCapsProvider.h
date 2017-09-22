#ifndef JXMPP_DUMMYENTITYCAPSPROVIDER_H
#define JXMPP_DUMMYENTITYCAPSPROVIDER_H

#include <map>

#include <JXMPP/Base/API.h>
#include <JXMPP/Disco/EntityCapsProvider.h>

namespace JXMPP {
    class JXMPP_API DummyEntityCapsProvider : public EntityCapsProvider {
        public:
            DummyEntityCapsProvider() {
            }

            DiscoInfo::ref getCaps(const JID& jid) const;

            DiscoInfo::ref getCapsCached(const JID& jid);

            std::map<JID, DiscoInfo::ref> caps;
    };
}

#endif // JXMPP_DUMMYENTITYCAPSPROVIDER_H
