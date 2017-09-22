#include <JXMPP/Avatars/OfflineAvatarManager.h>

#include <boost/bind.hpp>

#include <JXMPP/Avatars/AvatarStorage.h>

namespace JXMPP {

OfflineAvatarManager::OfflineAvatarManager(AvatarStorage* avatarStorage) : avatarStorage(avatarStorage) {
}

OfflineAvatarManager::~OfflineAvatarManager() {
}

boost::optional<std::string> OfflineAvatarManager::getAvatarHash(const JID& jid) const {
    return avatarStorage->getAvatarForJID(jid);
}

void OfflineAvatarManager::setAvatar(const JID& jid, const std::string& hash) {
    if (getAvatarHash(jid) != hash) {
        avatarStorage->setAvatarForJID(jid, hash);
        onAvatarChanged(jid);
    }
}

}
