#ifndef JXMPP_MIXREGISTERNICKSERIALIZER_H
#define JXMPP_MIXREGISTERNICKSERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXRegisterNick.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MIXRegisterNickSerializer : public GenericPayloadSerializer<MIXRegisterNick> {
        public:
            MIXRegisterNickSerializer();

            virtual std::string serializePayload(std::shared_ptr<MIXRegisterNick> payload) const override;
    };
}

#endif // JXMPP_MIXREGISTERNICKSERIALIZER_H
