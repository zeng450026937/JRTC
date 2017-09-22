#ifndef JXMPP_STATUSSERIALIZER_H
#define JXMPP_STATUSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Status.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {
    class JXMPP_API StatusSerializer : public GenericPayloadSerializer<Status> {
        public:
            StatusSerializer() : GenericPayloadSerializer<Status>() {}

            virtual std::string serializePayload(std::shared_ptr<Status> status)  const {
                XMLElement element("status");
                element.addNode(std::make_shared<XMLTextNode>(status->getText()));
                return element.serialize();
            }
    };
}

#endif // JXMPP_STATUSSERIALIZER_H
