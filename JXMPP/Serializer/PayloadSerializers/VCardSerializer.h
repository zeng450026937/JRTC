#ifndef JXMPP_VCARDSERIALIZER_H
#define JXMPP_VCARDSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/VCard.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API VCardSerializer : public GenericPayloadSerializer<VCard> {
        public:
            VCardSerializer();

            virtual std::string serializePayload(std::shared_ptr<VCard>)  const;
    };
}

#endif // JXMPP_VCARDSERIALIZER_H
