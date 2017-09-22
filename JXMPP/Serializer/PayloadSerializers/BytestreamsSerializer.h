#ifndef JXMPP_BYTESTREAMSSERIALIZER_H
#define JXMPP_BYTESTREAMSSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Bytestreams.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API BytestreamsSerializer : public GenericPayloadSerializer<Bytestreams> {
        public:
            BytestreamsSerializer();

            virtual std::string serializePayload(std::shared_ptr<Bytestreams>)  const;
    };
}

#endif // JXMPP_BYTESTREAMSSERIALIZER_H
