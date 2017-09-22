#ifndef JXMPP_IDLESERIALIZER_H
#define JXMPP_IDLESERIALIZER_H

/*
 * Copyright (c) 2013 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */




#include <JXMPP/Base/API.h>
#include <JXMPP/Base/DateTime.h>
#include <JXMPP/Elements/Idle.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API IdleSerializer : public GenericPayloadSerializer<Idle> {
        public:
            IdleSerializer() : GenericPayloadSerializer<Idle>() {}

            virtual std::string serializePayload(std::shared_ptr<Idle> idle)  const {
                return "<idle xmlns='urn:xmpp:idle:1' since='" + dateTimeToString(idle->getSince()) + "'/>";
            }
    };
}

#endif // JXMPP_IDLESERIALIZER_H
