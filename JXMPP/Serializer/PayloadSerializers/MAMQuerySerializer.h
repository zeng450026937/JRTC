#ifndef JXMPP_MAMQUERYSERIALIZER_H
#define JXMPP_MAMQUERYSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/MAMQuery.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API MAMQuerySerializer : public GenericPayloadSerializer<MAMQuery> {
        public:
            MAMQuerySerializer();
            virtual ~MAMQuerySerializer() override;

            virtual std::string serializePayload(std::shared_ptr<MAMQuery>) const override;
    };
}

#endif // JXMPP_MAMQUERYSERIALIZER_H
