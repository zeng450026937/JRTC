#ifndef JXMPP_SEARCHPAYLOADSERIALIZER_H
#define JXMPP_SEARCHPAYLOADSERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/SearchPayload.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API SearchPayloadSerializer : public GenericPayloadSerializer<SearchPayload> {
        public:
            SearchPayloadSerializer();

            virtual std::string serializePayload(std::shared_ptr<SearchPayload>)  const;
    };
}

#endif // JXMPP_SEARCHPAYLOADSERIALIZER_H
