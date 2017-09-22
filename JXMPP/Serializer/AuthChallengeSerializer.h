#ifndef JXMPP_AUTHCHALLENGESERIALIZER_H
#define JXMPP_AUTHCHALLENGESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/AuthChallenge.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API AuthChallengeSerializer : public GenericElementSerializer<AuthChallenge> {
        public:
            AuthChallengeSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element)  const;
    };
}

#endif // JXMPP_AUTHCHALLENGESERIALIZER_H
