#ifndef JXMPP_STARTTLSFAILURESERIALIZER_H
#define JXMPP_STARTTLSFAILURESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StartTLSFailure.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API StartTLSFailureSerializer : public GenericElementSerializer<StartTLSFailure> {
        public:
            StartTLSFailureSerializer() : GenericElementSerializer<StartTLSFailure>() {
            }

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const {
                return createSafeByteArray(XMLElement("failure", "urn:ietf:params:xml:ns:xmpp-tls").serialize());
            }
    };
}

#endif // JXMPP_STARTTLSFAILURESERIALIZER_H
