#ifndef JXMPP_STREAMRESUMEDSERIALIZER_H
#define JXMPP_STREAMRESUMEDSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamResumed.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API StreamResumedSerializer : public GenericElementSerializer<StreamResumed> {
        public:
            StreamResumedSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const;
    };
}

#endif // JXMPP_STREAMRESUMEDSERIALIZER_H
