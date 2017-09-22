#ifndef JXMPP_JINGLEIBBTRANSPORTPAYLOADSERIALIZER_H
#define JXMPP_JINGLEIBBTRANSPORTPAYLOADSERIALIZER_H

/*
 * Copyright (c) 2011 Tobias Markmann
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */





#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/JingleIBBTransportPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API JingleIBBTransportPayloadSerializer : public GenericPayloadSerializer<JingleIBBTransportPayload> {
        public:
            JingleIBBTransportPayloadSerializer();

            virtual std::string serializePayload(std::shared_ptr<JingleIBBTransportPayload>)  const;
    };
}

#endif // JXMPP_JINGLEIBBTRANSPORTPAYLOADSERIALIZER_H
