#include <JXMPP/Serializer/StreamResumedSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Elements/StreamResumed.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

StreamResumedSerializer::StreamResumedSerializer() : GenericElementSerializer<StreamResumed>() {
}

SafeByteArray StreamResumedSerializer::serialize(std::shared_ptr<ToplevelElement> el) const {
    std::shared_ptr<StreamResumed> e(std::dynamic_pointer_cast<StreamResumed>(el));
    XMLElement element("resumed", "urn:xmpp:sm:2");
    element.setAttribute("previd", e->getResumeID());
    if (e->getHandledStanzasCount()) {
        element.setAttribute("h", boost::lexical_cast<std::string>(e->getHandledStanzasCount().get()));
    }
    return createSafeByteArray(element.serialize());
}
