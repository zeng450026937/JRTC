#include <JXMPP/Serializer/ComponentHandshakeSerializer.h>

#include <JXMPP/Elements/ComponentHandshake.h>

namespace JXMPP {

ComponentHandshakeSerializer::ComponentHandshakeSerializer() {
}

SafeByteArray ComponentHandshakeSerializer::serialize(std::shared_ptr<ToplevelElement> element)  const {
    std::shared_ptr<ComponentHandshake> handshake(std::dynamic_pointer_cast<ComponentHandshake>(element));
    return createSafeByteArray("<handshake>" + handshake->getData() + "</handshake>");
}

}
