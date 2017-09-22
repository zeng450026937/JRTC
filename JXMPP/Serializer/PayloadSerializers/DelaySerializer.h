#ifndef JXMPP_DELAYSERIALIZER_H
#define JXMPP_DELAYSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Delay.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API DelaySerializer : public GenericPayloadSerializer<Delay> {
        public:
            DelaySerializer();

            virtual std::string serializePayload(std::shared_ptr<Delay>)  const;
    };
}

#endif // JXMPP_DELAYSERIALIZER_H
