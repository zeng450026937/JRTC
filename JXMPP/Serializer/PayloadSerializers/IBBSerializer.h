#ifndef JXMPP_IBBSERIALIZER_H
#define JXMPP_IBBSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/IBB.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API IBBSerializer : public GenericPayloadSerializer<IBB> {
        public:
            IBBSerializer();

            virtual std::string serializePayload(std::shared_ptr<IBB>)  const;
    };
}

#endif // JXMPP_IBBSERIALIZER_H
