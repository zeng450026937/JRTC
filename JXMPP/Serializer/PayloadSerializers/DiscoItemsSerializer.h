#ifndef JXMPP_DISCOITEMSSERIALIZER_H
#define JXMPP_DISCOITEMSSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/DiscoItems.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API DiscoItemsSerializer : public GenericPayloadSerializer<DiscoItems> {
        public:
            DiscoItemsSerializer();

            virtual std::string serializePayload(std::shared_ptr<DiscoItems>)  const;
    };
}

#endif // JXMPP_DISCOITEMSSERIALIZER_H
