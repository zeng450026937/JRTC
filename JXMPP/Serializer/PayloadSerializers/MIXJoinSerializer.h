#ifndef JXMPP_MIXJOINSERIALIZER_H
#define JXMPP_MIXJOINSERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXJoin.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {

    class JXMPP_API MIXJoinSerializer : public GenericPayloadSerializer<MIXJoin> {
        public:
            MIXJoinSerializer();
            virtual ~MIXJoinSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<MIXJoin>) const override;
    };
}

#endif // JXMPP_MIXJOINSERIALIZER_H
