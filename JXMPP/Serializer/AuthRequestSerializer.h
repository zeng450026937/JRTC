#ifndef JXMPP_AUTHREQUESTSERIALIZER_H
#define JXMPP_AUTHREQUESTSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthRequest.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API AuthRequestSerializer : public GenericElementSerializer<AuthRequest> {
        public:
            AuthRequestSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element)  const;
    };
}

#endif // JXMPP_AUTHREQUESTSERIALIZER_H
