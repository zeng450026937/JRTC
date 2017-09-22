#ifndef JXMPP_STREAMERRORSERIALIZER_H
#define JXMPP_STREAMERRORSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamError.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API StreamErrorSerializer : public GenericElementSerializer<StreamError> {
        public:
            StreamErrorSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement> error) const;
    };
}

#endif // JXMPP_STREAMERRORSERIALIZER_H
