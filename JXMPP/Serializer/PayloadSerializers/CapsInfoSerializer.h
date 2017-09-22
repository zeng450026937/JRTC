#ifndef JXMPP_CAPSINFOSERIALIZER_H
#define JXMPP_CAPSINFOSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/CapsInfo.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API CapsInfoSerializer : public GenericPayloadSerializer<CapsInfo> {
        public:
            CapsInfoSerializer();

            virtual std::string serializePayload(std::shared_ptr<CapsInfo>)  const;
    };
}

#endif // JXMPP_CAPSINFOSERIALIZER_H
