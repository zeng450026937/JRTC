#include <JXMPP/Elements/VCard.h>

namespace JXMPP {

VCard::EMailAddress VCard::getPreferredEMailAddress() const {
    for (const auto& address : emailAddresses_) {
        if (address.isPreferred) {
            return address;
        }
    }
    if (!emailAddresses_.empty()) {
        return emailAddresses_[0];
    }
    return EMailAddress();
}


}
