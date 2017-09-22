#ifndef JXMPP_CHATSTATESERIALIZER_H
#define JXMPP_CHATSTATESERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ChatState.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API ChatStateSerializer : public GenericPayloadSerializer<ChatState> {
        public:
            ChatStateSerializer();

            virtual std::string serializePayload(std::shared_ptr<ChatState> error)  const;
    };
}

#endif // JXMPP_CHATSTATESERIALIZER_H
