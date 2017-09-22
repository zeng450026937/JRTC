#ifndef JXMPP_AUTHFAILURESERIALIZER_H
#define JXMPP_AUTHFAILURESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthFailure.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API AuthFailureSerializer : public GenericElementSerializer<AuthFailure> {
        public:
            AuthFailureSerializer() : GenericElementSerializer<AuthFailure>() {
            }

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const {
                return createSafeByteArray(XMLElement("failure", "urn:ietf:params:xml:ns:xmpp-sasl").serialize());
            }
    };
}

#endif // JXMPP_AUTHFAILURESERIALIZER_H
