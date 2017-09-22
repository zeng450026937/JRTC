#ifndef JXMPP_STARTTLSREQUESTSERIALIZER_H
#define JXMPP_STARTTLSREQUESTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StartTLSRequest.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API StartTLSRequestSerializer : public GenericElementSerializer<StartTLSRequest> {
        public:
            StartTLSRequestSerializer() : GenericElementSerializer<StartTLSRequest>() {
            }

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const {
                return createSafeByteArray(XMLElement("starttls", "urn:ietf:params:xml:ns:xmpp-tls").serialize());
            }
    };
}

#endif // JXMPP_STARTTLSREQUESTSERIALIZER_H
