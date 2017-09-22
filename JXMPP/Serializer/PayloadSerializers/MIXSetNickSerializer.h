#ifndef JXMPP_MIXSETNICKSERIALIZER_H
#define JXMPP_MIXSETNICKSERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXSetNick.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MIXSetNickSerializer : public GenericPayloadSerializer<MIXSetNick> {
        public:
            MIXSetNickSerializer();

            virtual std::string serializePayload(std::shared_ptr<MIXSetNick> payload) const override ;
    };
}

#endif // JXMPP_MIXSETNICKSERIALIZER_H
