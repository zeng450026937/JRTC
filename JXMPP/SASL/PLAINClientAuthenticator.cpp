#include <JXMPP/SASL/PLAINClientAuthenticator.h>

#include <JXMPP/Base/Concat.h>

namespace JXMPP {

PLAINClientAuthenticator::PLAINClientAuthenticator() : ClientAuthenticator("PLAIN") {
}

boost::optional<SafeByteArray> PLAINClientAuthenticator::getResponse() const {
    return concat(createSafeByteArray(getAuthorizationID()), createSafeByteArray('\0'), createSafeByteArray(getAuthenticationID()), createSafeByteArray('\0'), getPassword());
}

bool PLAINClientAuthenticator::setChallenge(const boost::optional<ByteArray>&) {
    return true;
}

}
