#include <JXMPP/Serializer/PayloadSerializers/DelaySerializer.h>

#include <memory>

#include <boost/date_time/posix_time/posix_time.hpp>

#include <JXMPP/Base/DateTime.h>
#include <JXMPP/Base/String.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {

DelaySerializer::DelaySerializer() : GenericPayloadSerializer<Delay>() {
}

std::string DelaySerializer::serializePayload(std::shared_ptr<Delay> delay)  const {
    XMLElement delayElement("delay", "urn:xmpp:delay");
    if (delay->getFrom() && delay->getFrom()->isValid()) {
        delayElement.setAttribute("from", delay->getFrom()->toString());
    }
    delayElement.setAttribute("stamp", dateTimeToString(delay->getStamp()));
    return delayElement.serialize();
}

}
