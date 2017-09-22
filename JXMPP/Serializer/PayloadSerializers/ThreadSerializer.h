#ifndef JXMPP_THREADSERIALIZER_H
#define JXMPP_THREADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Thread.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>
#include <JXMPP/Serializer/XML/XMLTextNode.h>

namespace JXMPP {
    class JXMPP_API ThreadSerializer : public GenericPayloadSerializer<Thread> {
        public:
            ThreadSerializer();
            virtual ~ThreadSerializer();

            virtual std::string serializePayload(std::shared_ptr<Thread> thread) const;
    };
}

#endif // JXMPP_THREADSERIALIZER_H
