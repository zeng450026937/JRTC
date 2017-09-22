#ifndef JXMPP_MIXLEAVESERIALIZER_H
#define JXMPP_MIXLEAVESERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXLeave.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MIXLeaveSerializer : public GenericPayloadSerializer<MIXLeave> {
        public:
            MIXLeaveSerializer();
            virtual ~MIXLeaveSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<MIXLeave>) const override;
    };
}

#endif // JXMPP_MIXLEAVESERIALIZER_H
