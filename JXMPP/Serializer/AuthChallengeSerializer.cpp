#include <JXMPP/Serializer/AuthChallengeSerializer.h>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Elements/AuthChallenge.h>
#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

AuthChallengeSerializer::AuthChallengeSerializer() {
}

SafeByteArray AuthChallengeSerializer::serialize(std::shared_ptr<ToplevelElement> element)  const {
    std::shared_ptr<AuthChallenge> authChallenge(std::dynamic_pointer_cast<AuthChallenge>(element));
    std::string value;
    boost::optional<std::vector<unsigned char> > message = authChallenge->getValue();
    if (message) {
        if ((*message).empty()) {
            value = "=";
        }
        else {
            value = Base64::encode(ByteArray(*message));
        }
    }
    return createSafeByteArray("<challenge xmlns=\"urn:ietf:params:xml:ns:xmpp-sasl\">" + value + "</challenge>");
}

}
