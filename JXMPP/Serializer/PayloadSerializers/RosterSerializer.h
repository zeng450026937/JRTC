#ifndef JXMPP_ROSTERSERIALIZER_H
#define JXMPP_ROSTERSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RosterPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API RosterSerializer : public GenericPayloadSerializer<RosterPayload> {
        public:
            RosterSerializer();

            virtual std::string serializePayload(std::shared_ptr<RosterPayload>)  const;
    };
}

#endif // JXMPP_ROSTERSERIALIZER_H
