#ifndef JXMPP_MIXPAYLOADSERIALIZER_H
#define JXMPP_MIXPAYLOADSERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MIXPayloadSerializer : public GenericPayloadSerializer<MIXPayload> {
        public:
            MIXPayloadSerializer();

            virtual std::string serializePayload(std::shared_ptr<MIXPayload> payload) const override;
    };
}

#endif // JXMPP_MIXPAYLOADSERIALIZER_H
