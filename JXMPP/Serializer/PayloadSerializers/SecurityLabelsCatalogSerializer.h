#ifndef JXMPP_SECURITYLABELSCATALOGSERIALIZER_H
#define JXMPP_SECURITYLABELSCATALOGSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SecurityLabelsCatalog.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API SecurityLabelsCatalogSerializer : public GenericPayloadSerializer<SecurityLabelsCatalog> {
        public:
            SecurityLabelsCatalogSerializer();

            virtual std::string serializePayload(std::shared_ptr<SecurityLabelsCatalog> version)  const;
    };
}

#endif // JXMPP_SECURITYLABELSCATALOGSERIALIZER_H
