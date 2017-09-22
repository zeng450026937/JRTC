#ifndef JXMPP_COMPONENTHANDSHAKESERIALIZER_H
#define JXMPP_COMPONENTHANDSHAKESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ComponentHandshake.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API ComponentHandshakeSerializer : public GenericElementSerializer<ComponentHandshake> {
        public:
            ComponentHandshakeSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> element)  const;
    };
}

#endif // JXMPP_COMPONENTHANDSHAKESERIALIZER_H
