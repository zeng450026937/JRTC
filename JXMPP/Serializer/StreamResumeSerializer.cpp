#include <JXMPP/Serializer/StreamResumeSerializer.h>

#include <memory>

#include <boost/lexical_cast.hpp>

#include <JXMPP/Elements/StreamResume.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

using namespace JXMPP;

StreamResumeSerializer::StreamResumeSerializer() : GenericElementSerializer<StreamResume>() {
}

SafeByteArray StreamResumeSerializer::serialize(std::shared_ptr<ToplevelElement> el) const {
    std::shared_ptr<StreamResume> e(std::dynamic_pointer_cast<StreamResume>(el));
    XMLElement element("resume", "urn:xmpp:sm:2");
    element.setAttribute("previd", e->getResumeID());
    if (e->getHandledStanzasCount()) {
        element.setAttribute("h", boost::lexical_cast<std::string>(e->getHandledStanzasCount().get()));
    }
    return createSafeByteArray(element.serialize());
}
