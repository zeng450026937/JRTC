#ifndef JXMPP_RESOURCEBINDSERIALIZER_H
#define JXMPP_RESOURCEBINDSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ResourceBind.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API ResourceBindSerializer : public GenericPayloadSerializer<ResourceBind> {
        public:
            ResourceBindSerializer();

            virtual std::string serializePayload(std::shared_ptr<ResourceBind>)  const;
    };
}

#endif // JXMPP_RESOURCEBINDSERIALIZER_H
