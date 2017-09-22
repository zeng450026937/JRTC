#ifndef JXMPP_PAYLOADSERIALIZER_H
#define JXMPP_PAYLOADSERIALIZER_H

#include <memory>
#include <string>

#include <JXMPP/Base/API.h>

namespace JXMPP {
    class Payload;

    class JXMPP_API PayloadSerializer {
        public:
            virtual ~PayloadSerializer();

            virtual bool canSerialize(std::shared_ptr<Payload>) const = 0;
            virtual std::string serialize(std::shared_ptr<Payload>) const = 0;
    };
}

#endif // JXMPP_PAYLOADSERIALIZER_H
