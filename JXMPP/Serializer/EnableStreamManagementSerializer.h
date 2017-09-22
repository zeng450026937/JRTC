#ifndef JXMPP_ENABLESTREAMMANAGEMENTSERIALIZER_H
#define JXMPP_ENABLESTREAMMANAGEMENTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/EnableStreamManagement.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>
#include <JXMPP/Serializer/XML/XMLElement.h>

namespace JXMPP {
    class JXMPP_API EnableStreamManagementSerializer : public GenericElementSerializer<EnableStreamManagement> {
        public:
            EnableStreamManagementSerializer() : GenericElementSerializer<EnableStreamManagement>() {
            }

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const {
                return createSafeByteArray(XMLElement("enable", "urn:xmpp:sm:2").serialize());
            }
    };
}

#endif // JXMPP_ENABLESTREAMMANAGEMENTSERIALIZER_H
