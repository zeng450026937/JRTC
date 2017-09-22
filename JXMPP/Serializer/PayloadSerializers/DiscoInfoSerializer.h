#ifndef JXMPP_DISCOINFOSERIALIZER_H
#define JXMPP_DISCOINFOSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoInfo.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API DiscoInfoSerializer : public GenericPayloadSerializer<DiscoInfo> {
        public:
            DiscoInfoSerializer();

            virtual std::string serializePayload(std::shared_ptr<DiscoInfo>)  const;
    };
}

#endif // JXMPP_DISCOINFOSERIALIZER_H
