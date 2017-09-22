#ifndef JXMPP_INBANDREGISTRATIONPAYLOADSERIALIZER_H
#define JXMPP_INBANDREGISTRATIONPAYLOADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/InBandRegistrationPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API InBandRegistrationPayloadSerializer : public GenericPayloadSerializer<InBandRegistrationPayload> {
        public:
            InBandRegistrationPayloadSerializer();

            virtual std::string serializePayload(std::shared_ptr<InBandRegistrationPayload>)  const;
    };
}

#endif // JXMPP_INBANDREGISTRATIONPAYLOADSERIALIZER_H
