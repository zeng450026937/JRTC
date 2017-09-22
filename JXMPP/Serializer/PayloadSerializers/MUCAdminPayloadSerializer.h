#ifndef JXMPP_MUCADMINPAYLOADSERIALIZER_H
#define JXMPP_MUCADMINPAYLOADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MUCAdminPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MUCAdminPayloadSerializer : public GenericPayloadSerializer<MUCAdminPayload> {
        public:
            MUCAdminPayloadSerializer();
            std::string affiliationToString(MUCOccupant::Affiliation affiliation) const;
            std::string roleToString(MUCOccupant::Role role) const;

            virtual std::string serializePayload(std::shared_ptr<MUCAdminPayload> version)  const;
    };
}

#endif // JXMPP_MUCADMINPAYLOADSERIALIZER_H
