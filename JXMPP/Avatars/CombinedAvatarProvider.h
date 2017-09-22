#ifndef JXMPP_COMBINEDAVATARPROVIDER_H
#define JXMPP_COMBINEDAVATARPROVIDER_H

#include <map>
#include <vector>

#include <JXMPP/Avatars/AvatarProvider.h>
#include <JXMPP/Base/API.h>
#include <JXMPP/JID/JID.h>

namespace JXMPP {
    class JXMPP_API CombinedAvatarProvider : public AvatarProvider {
        public:
            virtual boost::optional<std::string> getAvatarHash(const JID&) const;

            void addProvider(AvatarProvider*);
            void removeProvider(AvatarProvider*);

        private:
            void handleAvatarChanged(const JID&);
            boost::optional<std::string> getCombinedAvatarAndCache(const JID&) const;

        private:
            std::vector<AvatarProvider*> providers;
            mutable std::map<JID, std::string> avatars;
    };
}

#endif // JXMPP_COMBINEDAVATARPROVIDER_H
