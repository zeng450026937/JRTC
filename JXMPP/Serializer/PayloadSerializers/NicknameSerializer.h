#ifndef JXMPP_NICKNAMESERIALIZER_H
#define JXMPP_NICKNAMESERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Nickname.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API NicknameSerializer : public GenericPayloadSerializer<Nickname> {
        public:
            NicknameSerializer();

            virtual std::string serializePayload(std::shared_ptr<Nickname>)  const;
    };
}

#endif // JXMPP_NICKNAMESERIALIZER_H
