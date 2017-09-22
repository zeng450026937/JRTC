#ifndef JXMPP_SECURITYLABELSERIALIZER_H
#define JXMPP_SECURITYLABELSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SecurityLabel.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API SecurityLabelSerializer : public GenericPayloadSerializer<SecurityLabel> {
        public:
            SecurityLabelSerializer();

            virtual std::string serializePayload(std::shared_ptr<SecurityLabel> version)  const;
    };
}

#endif // JXMPP_SECURITYLABELSERIALIZER_H
