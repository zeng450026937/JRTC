#ifndef JXMPP_MAMFINSERIALIZER_H
#define JXMPP_MAMFINSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MAMFin.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MAMFinSerializer : public GenericPayloadSerializer<MAMFin> {
        public:
            MAMFinSerializer();
            virtual ~MAMFinSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<MAMFin>) const override;
    };
}

#endif // JXMPP_MAMFINSERIALIZER_H
