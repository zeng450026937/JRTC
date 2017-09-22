#ifndef JXMPP_BODYSERIALIZER_H
#define JXMPP_BODYSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Body.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {
    class JXMPP_API BodySerializer : public GenericPayloadSerializer<Body> {
        public:
            BodySerializer() : GenericPayloadSerializer<Body>() {}

            virtual std::string serializePayload(std::shared_ptr<Body> body)  const {
                XMLTextNode textNode(body->getText());
                return "<body>" + textNode.serialize() + "</body>";
            }
    };
}

#endif // JXMPP_BODYSERIALIZER_H
