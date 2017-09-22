#ifndef JXMPP_AUTHSUCCESSSERIALIZER_H
#define JXMPP_AUTHSUCCESSSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthSuccess.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API AuthSuccessSerializer : public GenericElementSerializer<AuthSuccess> {
        public:
            AuthSuccessSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element)  const;
    };
}

#endif // JXMPP_AUTHSUCCESSSERIALIZER_H
