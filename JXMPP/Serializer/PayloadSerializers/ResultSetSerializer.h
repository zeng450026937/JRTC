#ifndef JXMPP_RESULTSETSERIALIZER_H
#define JXMPP_RESULTSETSERIALIZER_H

#include <memory>

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/ResultSet.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API ResultSetSerializer : public GenericPayloadSerializer<ResultSet> {
        public:
            ResultSetSerializer();
            virtual ~ResultSetSerializer() override;

            virtual std::string serializePayload(std::shared_ptr<ResultSet>) const override;
    };
}

#endif // JXMPP_RESULTSETSERIALIZER_H
