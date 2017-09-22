#ifndef JXMPP_RAWXMLPAYLOADSERIALIZER_H
#define JXMPP_RAWXMLPAYLOADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/RawXMLPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API RawXMLPayloadSerializer : public GenericPayloadSerializer<RawXMLPayload> {
        public:
            RawXMLPayloadSerializer() : GenericPayloadSerializer<RawXMLPayload>() {}

            virtual std::string serializePayload(std::shared_ptr<RawXMLPayload> p)  const {
                return p->getRawXML();
            }
    };
}

#endif // JXMPP_RAWXMLPAYLOADSERIALIZER_H
