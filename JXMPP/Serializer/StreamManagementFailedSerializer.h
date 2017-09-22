#ifndef JXMPP_STREAMMANAGEMENTFAILEDSERIALIZER_H
#define JXMPP_STREAMMANAGEMENTFAILEDSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamManagementFailed.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API StreamManagementFailedSerializer : public GenericElementSerializer<StreamManagementFailed> {
        public:
            StreamManagementFailedSerializer() : GenericElementSerializer<StreamManagementFailed>() {
            }

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const {
                return createSafeByteArray(XMLElement("failed", "urn:xmpp:sm:2").serialize());
            }
    };
}

#endif // JXMPP_STREAMMANAGEMENTFAILEDSERIALIZER_H
