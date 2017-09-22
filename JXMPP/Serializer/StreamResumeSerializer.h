#ifndef JXMPP_STREAMRESUMESERIALIZER_H
#define JXMPP_STREAMRESUMESERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/StreamResume.h>
#include <JXMPP/Serializer/GenericElementSerializer.h>

namespace JXMPP {
    class JXMPP_API StreamResumeSerializer : public GenericElementSerializer<StreamResume> {
        public:
            StreamResumeSerializer();

            virtual SafeByteArray serialize(std::shared_ptr<ToplevelElement>) const;
    };
}

#endif // JXMPP_STREAMRESUMESERIALIZER_H
