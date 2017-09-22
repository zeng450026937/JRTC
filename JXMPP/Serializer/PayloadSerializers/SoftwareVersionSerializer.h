#ifndef JXMPP_SOFTWAREVERSIONSERIALIZER_H
#define JXMPP_SOFTWAREVERSIONSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SoftwareVersion.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API SoftwareVersionSerializer : public GenericPayloadSerializer<SoftwareVersion> {
        public:
            SoftwareVersionSerializer();

            virtual std::string serializePayload(std::shared_ptr<SoftwareVersion> version)  const;
    };
}

#endif // JXMPP_SOFTWAREVERSIONSERIALIZER_H
