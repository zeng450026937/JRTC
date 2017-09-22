#ifndef JXMPP_AUTHRESPONSESERIALIZER_H
#define JXMPP_AUTHRESPONSESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthResponse.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API AuthResponseSerializer : public GenericElementSerializer<AuthResponse> {
        public:
            AuthResponseSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element)  const;
    };
}

#endif // JXMPP_AUTHRESPONSESERIALIZER_H
