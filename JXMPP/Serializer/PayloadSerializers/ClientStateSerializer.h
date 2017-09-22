#ifndef JXMPP_CLIENTSTATESERIALIZER_H
#define JXMPP_CLIENTSTATESERIALIZER_H

/*
 * Copyright (c) 2017 Tarun Gupta.
 * Licensed under the simplified BSD license.
 * See Documentation/Licenses/BSD-simplified.txt for more information.
 */



#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ClientState.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API ClientStateSerializer : public GenericPayloadSerializer<ClientState> {
        public:
            ClientStateSerializer();

            virtual std::string serializePayload(std::shared_ptr<ClientState> error)  const;
    };
}

#endif // JXMPP_CLIENTSTATESERIALIZER_H
