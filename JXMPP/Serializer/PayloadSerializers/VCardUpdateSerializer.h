#ifndef JXMPP_VCARDUPDATESERIALIZER_H
#define JXMPP_VCARDUPDATESERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/VCardUpdate.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API VCardUpdateSerializer : public GenericPayloadSerializer<VCardUpdate> {
        public:
            VCardUpdateSerializer();

            virtual std::string serializePayload(std::shared_ptr<VCardUpdate>)  const;
    };
}

#endif // JXMPP_VCARDUPDATESERIALIZER_H
