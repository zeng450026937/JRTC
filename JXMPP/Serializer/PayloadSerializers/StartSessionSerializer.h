#ifndef JXMPP_STARTSESSIONSERIALIZER_H
#define JXMPP_STARTSESSIONSERIALIZER_H

#include <boost/lexical_cast.hpp>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StartSession.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API StartSessionSerializer : public GenericPayloadSerializer<StartSession> {
        public:
            StartSessionSerializer() : GenericPayloadSerializer<StartSession>() {}

            virtual std::string serializePayload(std::shared_ptr<StartSession>)  const {
                return XMLElement("session", "urn:ietf:params:xml:ns:xmpp-session").serialize();
            }
    };
}

#endif // JXMPP_STARTSESSIONSERIALIZER_H
