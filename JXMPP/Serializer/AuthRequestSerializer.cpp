#include <JXMPP/Serializer/AuthRequestSerializer.h>

#include <JXMPP/Base/Concat.h>
#include <JXMPP/Base/SafeByteArray.h>
#include <JXMPP/Elements/AuthRequest.h>
#include <JXMPP/StringCodecs/Base64.h>

namespace JXMPP {

AuthRequestSerializer::AuthRequestSerializer() {
}

SafeByteArray AuthRequestSerializer::serialize(std::shared_ptr<ToplevelElement> element)  const {
    std::shared_ptr<AuthRequest> authRequest(std::dynamic_pointer_cast<AuthRequest>(element));
    SafeByteArray value;
    boost::optional<SafeByteArray> message = authRequest->getMessage();
    if (message) {
        if ((*message).empty()) {
            value = createSafeByteArray("=");
        }
        else {
            value = Base64::encode(*message);
        }
    }
    return concat(createSafeByteArray("<auth xmlns=\"urn:ietf:params:xml:ns:xmpp-sasl\" mechanism=\"" + authRequest->getMechanism() + "\">"), value, createSafeByteArray("</auth>"));
}

}
