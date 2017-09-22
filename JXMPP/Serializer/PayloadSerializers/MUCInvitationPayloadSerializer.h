#ifndef JXMPP_MUCINVITATIONPAYLOADSERIALIZER_H
#define JXMPP_MUCINVITATIONPAYLOADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCInvitationPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MUCInvitationPayloadSerializer : public GenericPayloadSerializer<MUCInvitationPayload> {
        public:
            MUCInvitationPayloadSerializer();

            virtual std::string serializePayload(std::shared_ptr<MUCInvitationPayload> version)  const;
    };
}

#endif // JXMPP_MUCINVITATIONPAYLOADSERIALIZER_H
