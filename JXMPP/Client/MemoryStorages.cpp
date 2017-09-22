#include <JXMPP/Client/MemoryStorages.h>
#include <JXMPP/VCards/VCardMemoryStorage.h>
#include <JXMPP/Avatars/AvatarMemoryStorage.h>
#include <JXMPP/Disco/CapsMemoryStorage.h>
#include <JXMPP/Roster/RosterMemoryStorage.h>
#ifdef JXMPP_EXPERIMENTAL_HISTORY
#include <JXMPP/History/SQLiteHistoryStorage.h>
#endif

namespace JXMPP {

MemoryStorages::MemoryStorages(CryptoProvider* crypto) {
    vcardStorage = new VCardMemoryStorage(crypto);
    capsStorage = new CapsMemoryStorage();
    avatarStorage = new AvatarMemoryStorage();
    rosterStorage = new RosterMemoryStorage();
#ifdef JXMPP_EXPERIMENTAL_HISTORY
    historyStorage = new SQLiteHistoryStorage(":memory:");
#else
    historyStorage = nullptr;
#endif
}

MemoryStorages::~MemoryStorages() {
    delete rosterStorage;
    delete avatarStorage;
    delete capsStorage;
    delete vcardStorage;
#ifdef JXMPP_EXPERIMENTAL_HISTORY
    delete historyStorage;
#endif
}

VCardStorage* MemoryStorages::getVCardStorage() const {
    return vcardStorage;
}

CapsStorage* MemoryStorages::getCapsStorage() const {
    return capsStorage;
}

AvatarStorage* MemoryStorages::getAvatarStorage() const {
    return avatarStorage;
}

RosterStorage* MemoryStorages::getRosterStorage() const {
    return rosterStorage;
}

HistoryStorage* MemoryStorages::getHistoryStorage() const {
#ifdef JXMPP_EXPERIMENTAL_HISTORY
    return historyStorage;
#else
    return nullptr;
#endif
}


}
