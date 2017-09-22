#ifndef JXMPP_MIXPARTICIPANTSERIALIZER_H
#define JXMPP_MIXPARTICIPANTSERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MIXParticipant.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MIXParticipantSerializer : public GenericPayloadSerializer<MIXParticipant> {
        public:
            MIXParticipantSerializer();

            virtual std::string serializePayload(std::shared_ptr<MIXParticipant> participant)  const;
    };
}

#endif // JXMPP_MIXPARTICIPANTSERIALIZER_H
