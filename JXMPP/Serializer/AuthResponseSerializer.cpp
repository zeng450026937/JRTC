#include <JXMPP/Serializer/AuthResponseSerializer.h>

#include <JXMPP/Base/Concat.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Elements/AuthResponse.h>
#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

AuthResponseSerializer::AuthResponseSerializer() {
}

SafeByteArray AuthResponseSerializer::serialize(std::shared_ptr<ToplevelElement> element)    const {
    std::shared_ptr<AuthResponse> authResponse(std::dynamic_pointer_cast<AuthResponse>(element));
    SafeByteArray value;
    boost::optional<SafeByteArray> message = authResponse->getValue();
    if (message) {
        if ((*message).empty()) {
            value = createSafeByteArray("");
        }
        else {
            value = Base64::encode(*message);
        }
    }
    return concat(createSafeByteArray("<response xmlns=\"urn:ietf:params:xml:ns:xmpp-sasl\">"), value, createSafeByteArray("</response>"));
}

}
