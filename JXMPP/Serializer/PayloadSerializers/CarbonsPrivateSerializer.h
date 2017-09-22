#ifndef JXMPP_CARBONSPRIVATESERIALIZER_H
#define JXMPP_CARBONSPRIVATESERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CarbonsPrivate.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API CarbonsPrivateSerializer : public GenericPayloadSerializer<CarbonsPrivate> {
        public:
            CarbonsPrivateSerializer();
            virtual ~CarbonsPrivateSerializer();

            virtual std::string serializePayload(std::shared_ptr<CarbonsPrivate>)    const;
    };
}

#endif // JXMPP_CARBONSPRIVATESERIALIZER_H
