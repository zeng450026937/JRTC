#include <JXMPP/Avatars/VCardUpdateAvatarManager.h>

#include <boost/bind.hpp>

#include <JXMPP/Avatars/AvatarStorage.h>
#include <JXMPP/Base/Log.h>
#include <JXMPP/Client/StanzaChannel.h>
#include <JXMPP/Crypto/CryptoProvider.h>
#include <JXMPP/Elements/VCardUpdate.h>
#include <JXMPP/MUC/MUCRegistry.h>
#include <JXMPP/StringCodecs/Hexify.h>
#include <JXMPP/VCards/GetVCardRequest.h>
#include <JXMPP/VCards/VCardManager.h>

namespace JXMPP {

VCardUpdateAvatarManager::VCardUpdateAvatarManager(VCardManager* vcardManager, StanzaChannel* stanzaChannel, AvatarStorage* avatarStorage, CryptoProvider* crypto, MUCRegistry* mucRegistry) : vcardManager_(vcardManager), avatarStorage_(avatarStorage), crypto_(crypto), mucRegistry_(mucRegistry) {
    stanzaChannel->onPresenceReceived.connect(boost::bind(&VCardUpdateAvatarManager::handlePresenceReceived, this, _1));
    stanzaChannel->onAvailableChanged.connect(boost::bind(&VCardUpdateAvatarManager::handleStanzaChannelAvailableChanged, this, _1));
    vcardManager_->onVCardChanged.connect(boost::bind(&VCardUpdateAvatarManager::handleVCardChanged, this, _1, _2));
}

void VCardUpdateAvatarManager::handlePresenceReceived(std::shared_ptr<Presence> presence) {
    std::shared_ptr<VCardUpdate> update = presence->getPayload<VCardUpdate>();
    if (!update || presence->getPayload<ErrorPayload>()) {
        return;
    }
    JID from = getAvatarJID(presence->getFrom());
    if (getAvatarHash(from) == update->getPhotoHash()) {
        return;
    }
    JXMPP_LOG(debug) << "Updated hash: " << from << " -> " << update->getPhotoHash() << std::endl;
    if (avatarStorage_->hasAvatar(update->getPhotoHash())) {
        setAvatarHash(from, update->getPhotoHash());
    }
    else {
        vcardManager_->requestVCard(from);
    }
}

void VCardUpdateAvatarManager::handleVCardChanged(const JID& from, VCard::ref vCard) {
    if (!vCard) {
        JXMPP_LOG(debug) << "Missing element: " << from << ": null vcard payload" << std::endl;
        return;
    }

    if (vCard->getPhoto().empty()) {
        setAvatarHash(from, "");
    }
    else {
        std::string hash = Hexify::hexify(crypto_->getSHA1Hash(vCard->getPhoto()));
        if (!avatarStorage_->hasAvatar(hash)) {
            avatarStorage_->addAvatar(hash, vCard->getPhoto());
        }
        setAvatarHash(from, hash);
    }
}

void VCardUpdateAvatarManager::setAvatarHash(const JID& from, const std::string& hash) {
    JXMPP_LOG(debug) << "Updating hash: " << from << " -> " << hash << std::endl;
    avatarHashes_[from] = hash;
    onAvatarChanged(from);
}

/*
void VCardUpdateAvatarManager::setAvatar(const JID& jid, const ByteArray& avatar) {
    std::string hash = Hexify::hexify(SHA1::getHash(avatar));
    avatarStorage_->addAvatar(hash, avatar);
    setAvatarHash(getAvatarJID(jid), hash);
}
*/

boost::optional<std::string> VCardUpdateAvatarManager::getAvatarHash(const JID& jid) const {
    std::map<JID, std::string>::const_iterator i = avatarHashes_.find(getAvatarJID(jid));
    if (i != avatarHashes_.end()) {
        return i->second;
    }
    else {
        return boost::optional<std::string>();
    }
}

JID VCardUpdateAvatarManager::getAvatarJID(const JID& jid) const {
    JID bareFrom = jid.toBare();
    return (mucRegistry_ && mucRegistry_->isMUC(bareFrom)) ? jid : bareFrom;
}

void VCardUpdateAvatarManager::handleStanzaChannelAvailableChanged(bool available) {
    if (available) {
        std::map<JID, std::string> oldAvatarHashes;
        avatarHashes_.swap(oldAvatarHashes);
        for(std::map<JID, std::string>::const_iterator i = oldAvatarHashes.begin(); i != oldAvatarHashes.end(); ++i) {
            onAvatarChanged(i->first);
        }
    }
}


}
