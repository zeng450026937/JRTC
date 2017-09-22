#include <JXMPP/Serializer/AuthSuccessSerializer.h>

#include <JXMPP/Base/ByteArray.h>
#include <JXMPP/Elements/AuthSuccess.h>
#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

AuthSuccessSerializer::AuthSuccessSerializer() {
}

SafeByteArray AuthSuccessSerializer::serialize(std::shared_ptr<ToplevelElement> element)  const {
    std::shared_ptr<AuthSuccess> authSuccess(std::dynamic_pointer_cast<AuthSuccess>(element));
    std::string value;
    boost::optional<std::vector<unsigned char> > message = authSuccess->getValue();
    if (message) {
        if ((*message).empty()) {
            value = "=";
        }
        else {
            value = Base64::encode(ByteArray(*message));
        }
    }
    return createSafeByteArray("<success xmlns=\"urn:ietf:params:xml:ns:xmpp-sasl\">" + value + "</success>");
}

}
