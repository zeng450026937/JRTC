#ifndef JXMPP_STORAGES_H
#define JXMPP_STORAGES_H

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class VCardStorage;
    class AvatarStorage;
    class CapsStorage;
    class RosterStorage;
    class HistoryStorage;

    /**
     * An interface to hold storage classes for different
     * controllers.
     */
    class JXMPP_API Storages {
        public:
            virtual ~Storages();

            virtual VCardStorage* getVCardStorage() const = 0;
            virtual AvatarStorage* getAvatarStorage() const = 0;
            virtual CapsStorage* getCapsStorage() const = 0;
            virtual RosterStorage* getRosterStorage() const = 0;
            virtual HistoryStorage* getHistoryStorage() const = 0;
    };
}

#endif // JXMPP_STORAGES_H
