#ifndef JXMPP_STORAGESERIALIZER_H
#define JXMPP_STORAGESERIALIZER_H

#include <JXMPP/Base/API.h>
#include <JXMPP/Elements/Storage.h>
#include <JXMPP/Serializer/GenericPayloadSerializer.h>

namespace JXMPP {
    class JXMPP_API StorageSerializer : public GenericPayloadSerializer<Storage> {
        public:
            StorageSerializer();

            virtual std::string serializePayload(std::shared_ptr<Storage>)  const;
    };
}

#endif // JXMPP_STORAGESERIALIZER_H
