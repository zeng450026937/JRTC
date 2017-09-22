#ifndef JXMPP_STREAMMANAGEMENTENABLEDSERIALIZER_H
#define JXMPP_STREAMMANAGEMENTENABLEDSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamManagementEnabled.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API StreamManagementEnabledSerializer : public GenericElementSerializer<StreamManagementEnabled> {
        public:
            StreamManagementEnabledSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const;
    };
}

#endif // JXMPP_STREAMMANAGEMENTENABLEDSERIALIZER_H
