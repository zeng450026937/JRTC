#ifndef JXMPP_PAYLOADSSERIALIZER_H
#define JXMPP_PAYLOADSSERIALIZER_H

#include <memory>
#include <string>

#include <JXMPP/Elements/Payload.h>
#include <JXMPP/Serializer/PayloadSerializers/FullPayloadSerializerCollection.h>

namespace JXMPP {
    class PayloadsSerializer {
        public:
            std::string serialize(std::shared_ptr<Payload> payload);

        private:
            FullPayloadSerializerCollection serializers;
    };
}

#endif // JXMPP_PAYLOADSSERIALIZER_H
