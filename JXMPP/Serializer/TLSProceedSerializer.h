#ifndef JXMPP_TLSPROCEEDSERIALIZER_H
#define JXMPP_TLSPROCEEDSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/TLSProceed.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API TLSProceedSerializer : public GenericElementSerializer<TLSProceed> {
        public:
            TLSProceedSerializer() : GenericElementSerializer<TLSProceed>() {
            }

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const {
                return createSafeByteArray(XMLElement("proceed", "urn:ietf:params:xml:ns:xmpp-tls").serialize());
            }
    };
}

#endif // JXMPP_TLSPROCEEDSERIALIZER_H
