#ifndef JXMPP_STREAMINITIATIONSERIALIZER_H
#define JXMPP_STREAMINITIATIONSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamInitiation.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API StreamInitiationSerializer : public GenericPayloadSerializer<StreamInitiation> {
        public:
            StreamInitiationSerializer();

            virtual std::string serializePayload(std::shared_ptr<StreamInitiation>)  const;
    };
}

#endif // JXMPP_STREAMINITIATIONSERIALIZER_H
