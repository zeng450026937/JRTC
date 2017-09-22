#ifndef JXMPP_STANZAACKREQUESTSERIALIZER_H
#define JXMPP_STANZAACKREQUESTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StanzaAckRequest.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API StanzaAckRequestSerializer : public GenericElementSerializer<StanzaAckRequest> {
        public:
            StanzaAckRequestSerializer() : GenericElementSerializer<StanzaAckRequest>() {
            }

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const {
                return createSafeByteArray(XMLElement("r", "urn:xmpp:sm:2").serialize());
            }
    };
}

#endif // JXMPP_STANZAACKREQUESTSERIALIZER_H
