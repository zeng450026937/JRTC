#include <JXMPP/VCards/VCardStorage.h>

#include <JXMPP/Crypto/CryptoProvider.h>
#include <JXMPP/StringCodecs/Hexify.h>

namespace JXMPP {

VCardStorage::VCardStorage(CryptoProvider* crypto) : crypto(crypto) {
}

VCardStorage::~VCardStorage() {
}

std::string VCardStorage::getPhotoHash(const JID& jid) const {
    VCard::ref vCard = getVCard(jid);
    if (vCard && !vCard->getPhoto().empty()) {
        return Hexify::hexify(crypto->getSHA1Hash(vCard->getPhoto()));
    }
    else {
        return "";
    }
}

}
