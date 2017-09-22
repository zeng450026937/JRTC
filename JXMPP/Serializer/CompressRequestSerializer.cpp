#include <JXMPP/Serializer/CompressRequestSerializer.h>

#include <JXMPP/Elements/CompressRequest.h>

namespace JXMPP {

CompressRequestSerializer::CompressRequestSerializer() {
}

SafeByteArray CompressRequestSerializer::serialize(std::shared_ptr<ToplevelElement> element)  const {
    std::shared_ptr<CompressRequest> compressRequest(std::dynamic_pointer_cast<CompressRequest>(element));
    return createSafeByteArray("<compress xmlns='http://jabber.org/protocol/compress'><method>" + compressRequest->getMethod() + "</method></compress>");
}

bool CompressRequestSerializer::canSerialize(std::shared_ptr<ToplevelElement> element) const {
    return std::dynamic_pointer_cast<CompressRequest>(element) != nullptr;
}

}
