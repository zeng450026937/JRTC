#ifndef JXMPP_MEMORYSTORAGES_H
#define JXMPP_MEMORYSTORAGES_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Client/Storages.h>

namespace JXMPP {
    class VCardMemoryStorage;
    class CryptoProvider;

    /**
     * An implementation of Storages for storing all
     * controller data in memory.
     */
    class JXMPP_API MemoryStorages : public Storages {
        public:
            MemoryStorages(CryptoProvider*);
            virtual ~MemoryStorages();

            virtual VCardStorage* getVCardStorage() const;
            virtual AvatarStorage* getAvatarStorage() const;
            virtual CapsStorage* getCapsStorage() const;
            virtual RosterStorage* getRosterStorage() const;
            virtual HistoryStorage* getHistoryStorage() const;

        private:
            VCardMemoryStorage* vcardStorage;
            AvatarStorage* avatarStorage;
            CapsStorage* capsStorage;
            RosterStorage* rosterStorage;
            HistoryStorage* historyStorage;
    };
}

#endif // JXMPP_MEMORYSTORAGES_H
