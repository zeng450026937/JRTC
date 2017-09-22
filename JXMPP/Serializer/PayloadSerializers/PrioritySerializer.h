#ifndef JXMPP_PRIORITYSERIALIZER_H
#define JXMPP_PRIORITYSERIALIZER_H

#include <boost/lexical_cast.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Priority.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API PrioritySerializer : public GenericPayloadSerializer<Priority> {
        public:
            PrioritySerializer() : GenericPayloadSerializer<Priority>() {}

            virtual std::string serializePayload(std::shared_ptr<Priority> priority)  const {
                return "<priority>" + boost::lexical_cast<std::string>(priority->getPriority()) + "</priority>";
            }
    };
}

#endif // JXMPP_PRIORITYSERIALIZER_H
